#include "PointModel.hpp"

int PointModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return this->points.size();
}

QVariant PointModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    const QPointF p = toQPointF(points.at(index.row()));
    return tr("%1: (%2, %3)").arg(index.row()).arg(p.x()).arg(p.y());
}

PointModel::PointModel(QObject *parent) : QAbstractListModel(parent) {}

QPointF PointModel::toQPointF(const Point &p) {
    return {p.getX(), p.getY()};
}

const std::vector<Point> &PointModel::getPoints() const {
    return this->points;
}
