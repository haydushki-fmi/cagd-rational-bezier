#include "Canvas.hpp"

#include <utility>

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
        emit pointAdded(Point(event->pos().x(), event->pos().y(), 1));
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
