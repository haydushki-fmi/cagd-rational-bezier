#ifndef CAGD_RATIONAL_BEZIER_POINTMODEL_HPP
#define CAGD_RATIONAL_BEZIER_POINTMODEL_HPP


#include <QAbstractListModel>
#include <QPointF>
#include "curve_lib/RationalBezierPoint.hpp"

using Point = CurveLib::RationalBezierPoint;

class PointModel : public QAbstractListModel {
public:
    explicit PointModel(QObject *parent);

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private:
    static QPointF toQPointF(const Point &);

private:
    std::vector<Point> points;
public:
    const std::vector<Point> &getPoints() const;

};


#endif //CAGD_RATIONAL_BEZIER_POINTMODEL_HPP
