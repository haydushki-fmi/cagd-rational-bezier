#include "Canvas.hpp"

#include <utility>
#include <QInputDialog>

const double MIN_WEIGHT = 0;
const double MAX_WEIGHT = 100;
const double DEFAULT_WEIGHT = 1;
const double WEIGHT_STEP = 0.1;
const int WEIGHT_PRECISION = 2;

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);
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
    QWidget::paintEvent(event);
}

void Canvas::drawPoints(QPainter &painter) {
    // TODO: Implement
}

void Canvas::drawTopLevelLines(QPainter &painter) {
    // TODO: Implement
}

void Canvas::drawBezierCurve(QPainter &painter, qreal progress) {
    // TODO: Implement
}

void Canvas::updateConfiguration() {
    // TODO: Implement
}

void Canvas::recalculateAndUpdate() {
    // TODO: Implement
}
