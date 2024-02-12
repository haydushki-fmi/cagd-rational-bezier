#include "PointModel.hpp"

int PointModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return this->points.size();
}

QVariant PointModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return {};

    const auto p = points.at(index.row());
    switch (role) {
        case Qt::DisplayRole:
            return tr("%1: (%2, %3, %4)").arg(index.row()).arg(p.getX()).arg(p.getY()).arg(p.getWeight());
        case Qt::EditRole:
            return p.getWeight();
        default:
            return {};
    }
}

PointModel::PointModel(QObject *parent) : QAbstractListModel(parent) {}

QPointF PointModel::toQPointF(const Point &p) {
    return {p.getX(), p.getY()};
}

const std::vector<Point> &PointModel::getPoints() const {
    return this->points;
}

void PointModel::clearPoints() {
    beginResetModel();
    this->points.clear();
    endResetModel();
}

void PointModel::addPoint(Point p) {
    beginInsertRows(QModelIndex(), this->points.size(), this->points.size());
    this->points.push_back(p);
    endInsertRows();
}

bool PointModel::removeRows(int row, int count, const QModelIndex &parent) {
    if (this->points.size() == 0) {
        return true;
    }
    beginRemoveRows(parent, row, row + (count - 1));
    for (int i = 0; i < count; ++i) {
        this->points.erase(this->points.begin() + row);
    }
    endRemoveRows();

    return true;

}

bool PointModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid()) {
        return false;
    }
    this->points.at(index.row()).setWeight(value.toDouble());
    emit dataChanged(index, index, {role});

    return true;
}
