#ifndef CAGD_RATIONAL_BEZIER_CANVAS_HPP
#define CAGD_RATIONAL_BEZIER_CANVAS_HPP


#include <QWidget>
#include <QPen>
#include <QMouseEvent>
#include "curve_lib/RationalBezierPoint.hpp"
#include "models/PointModel.hpp"

class Canvas : public QWidget {
Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);

    void setPointModel(std::shared_ptr<PointModel> model);

    virtual ~Canvas() = default;

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

public slots:

    void clear();

signals:

    void pointAdded(CurveLib::RationalBezierPoint);

private:
    void drawPoints(QPainter &painter);

    void drawTopLevelLines(QPainter &painter);

    void drawBezierCurve(QPainter &painter, qreal progress = 1.0);

    void updateConfiguration();

    void recalculateAndUpdate();

    std::vector<Point> calculatedBezierPoints;
    bool bezierCurveNeedsRecalculation;

    std::shared_ptr<PointModel> pointModel;
    qreal pointRadius;

    bool drawPointsToggle;
    bool connectPointsToggle;
    bool drawBezierCurveToggle;
    QPen pointPen;
    QBrush pointBrush;
    QPen lineBetweenPointsPen;
    QPen bezierCurvePen;
};


#endif //CAGD_RATIONAL_BEZIER_CANVAS_HPP
