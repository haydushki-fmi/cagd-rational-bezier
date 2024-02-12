#include <QInputDialog>
#include "PointListView.hpp"
#include "curve_lib/RationalBezierPoint.hpp"


// TODO: Move these in Point class
const double MIN_WEIGHT = 0;
const double MAX_WEIGHT = 100;
const double WEIGHT_STEP = 0.1;
const int WEIGHT_PRECISION = 2;

using Point = CurveLib::RationalBezierPoint;

PointListView::PointListView(QWidget *parent) : QListView(parent) {}

void PointListView::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        const int row = currentIndex().row();
        model()->removeRow(row);
    }
}

void PointListView::mouseDoubleClickEvent(QMouseEvent *event) {
    if (currentIndex().row() < 0) {
        return;
    }
    const double p = this->model()->data(currentIndex(), Qt::EditRole).toDouble();
    bool ok;
    double w = QInputDialog::getDouble(nullptr, tr("Тегло"), tr("Въведете тегло на точката:"), p,
                                       MIN_WEIGHT, MAX_WEIGHT, WEIGHT_PRECISION, &ok,
                                       Qt::WindowFlags(), WEIGHT_STEP);
    if (ok) {
        this->model()->setData(currentIndex(), w);
    }
}
