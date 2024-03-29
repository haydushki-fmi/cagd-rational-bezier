#ifndef CAGD_RATIONAL_BEZIER_POINTMODEL_HPP
#define CAGD_RATIONAL_BEZIER_POINTMODEL_HPP


#include <QAbstractListModel>
#include <QPointF>
#include "curve_lib/RationalBezierPoint.hpp"

using Point = CurveLib::RationalBezierPoint;

class PointModel : public QAbstractListModel {
public:
    explicit PointModel(QObject *parent = nullptr);

    [[nodiscard]] int rowCount(const QModelIndex &parent) const override;

    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

    [[nodiscard]] const std::vector<Point> &getPoints() const;

    void addPoint(Point p);

    void clearPoints();

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

public:
    static QPointF toQPointF(const Point &);

private:
    std::vector<Point> points;
};


#endif //CAGD_RATIONAL_BEZIER_POINTMODEL_HPP
