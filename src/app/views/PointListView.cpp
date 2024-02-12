#include "PointListView.hpp"

PointListView::PointListView(QWidget *parent) : QListView(parent) {}

void PointListView::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        const int row = currentIndex().row();
        model()->removeRow(row);
    }
}
