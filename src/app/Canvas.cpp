#include "Canvas.hpp"
#include "models/PointModel.hpp"
#include "curve_lib/DeCasteljauAlgorithm.hpp"

#include <utility>
#include <QInputDialog>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOption>


const double MIN_WEIGHT = 0;
const double MAX_WEIGHT = 100;
const double DEFAULT_WEIGHT = 1;
const double WEIGHT_STEP = 0.1;
const int WEIGHT_PRECISION = 2;

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);
    // TODO: Add connetction to settings
    this->updateConfiguration();
}

void Canvas::setPointModel(std::shared_ptr<PointModel> model) {
    this->pointModel = std::move(model);

    connect(this->pointModel.get(), &PointModel::dataChanged, this, &Canvas::recalculateAndUpdate);
    connect(this->pointModel.get(), &PointModel::rowsInserted, this, &Canvas::recalculateAndUpdate);
    connect(this->pointModel.get(), &PointModel::rowsRemoved, this, &Canvas::recalculateAndUpdate);
    update();
}

void Canvas::clear() {
    // TODO: Implement
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        bool ok;
        double w = QInputDialog::getDouble(nullptr, tr("Тегло"), tr("Въведете тегло на точката:"), DEFAULT_WEIGHT,
                                           MIN_WEIGHT, MAX_WEIGHT, WEIGHT_PRECISION, &ok,
                                           Qt::WindowFlags(), WEIGHT_STEP);
        if (ok) {
            emit pointAdded(Point(event->pos().x(), event->pos().y(), w));
        }
    }
    QWidget::mousePressEvent(event);
}

void Canvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QStyleOption option;
    option.initFrom(this);

    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);

    painter.setRenderHints(QPainter::Antialiasing);

    if (this->drawPointsToggle) {
        this->drawPoints(painter);
    }

    if (this->drawBezierCurveToggle) {
        for (double i = 0; i <= 1; i += this->step) {
            this->drawBezierCurve(painter, i);
        }
        if (this->connectPointsToggle) {
            this->drawTopLevelLines(painter);
        }
    }
    // TODO: draw intermediate lines at some point?
}

void Canvas::drawPoints(QPainter &painter) {
    painter.save();
    painter.setPen(this->pointPen);
    painter.setBrush(this->pointBrush);

    for (const auto &point: this->pointModel->getPoints()) {
        painter.drawEllipse(PointModel::toQPointF(point), this->pointRadius, this->pointRadius);
    }

    painter.restore();
}

void Canvas::drawTopLevelLines(QPainter &painter) {
    if (this->pointModel->getPoints().size() == 0) {
        return;
    }
    drawPoints(painter);
    painter.save();
    painter.setPen(Qt::red);

    for (int i = 0; i < this->pointModel->getPoints().size() - 1; ++i) {
        auto p1 = PointModel::toQPointF(this->pointModel->getPoints().at(i));
        auto p2 = PointModel::toQPointF(this->pointModel->getPoints().at(i + 1));

        painter.drawLine(p1, p2);
    }

    painter.restore();
}

void Canvas::drawBezierCurve(QPainter &painter, qreal progress) {
    painter.setPen(this->bezierCurvePen);

    if (this->bezierCurveNeedsRecalculation) {
        this->calculatedBezierPoints = CurveLib::DeCasteljauAlgorithm::generateCurvePoints(
                this->pointModel->getPoints(), this->step);
        this->bezierCurveNeedsRecalculation = false;
    }
    this->calculatedBezierPoints = CurveLib::DeCasteljauAlgorithm::generateCurvePoints(
            this->pointModel->getPoints(), this->step);

    if (this->calculatedBezierPoints.size() < 2)
        return;

    QPainterPath path;
    const int lastToConsider = qRound((this->calculatedBezierPoints.size()) * progress);
    path.moveTo(PointModel::toQPointF(this->calculatedBezierPoints.front()));
    for (int i = 1; i < lastToConsider; ++i) {
        path.lineTo(PointModel::toQPointF(this->calculatedBezierPoints.at(i)));
        if (progress == 1.0 && i + 1 == lastToConsider)
            path.lineTo(PointModel::toQPointF(this->pointModel->getPoints().back()));
    }

    painter.drawPath(path);
}

void Canvas::updateConfiguration() {
    // TODO: Implement
    this->drawBezierCurveToggle = true;
    this->drawPointsToggle = true;
    this->connectPointsToggle = true;
    this->step = 0.001;
    this->pointRadius = 2;
    this->pointPen = QPen(Qt::black);
    this->pointBrush = QBrush(Qt::lightGray);

    update();
}

void Canvas::recalculateAndUpdate() {
    if (this->drawBezierCurveToggle) {
        this->bezierCurveNeedsRecalculation = true;
    }

    update();
}
