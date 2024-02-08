#include "DeCasteljauAlgorithm.hpp"

namespace CurveLib {
    vector<Point> DeCasteljauAlgorithm::algorithmStep(const std::vector<RationalBezierPoint> &points, double t) {
        vector<Point> result;
        for (int i = 0; i < points.size() - 1; ++i) {
            const double x = ((1 - t) * points[i].getWeight() * points[i].getX() +
                              t * points[i + 1].getWeight() * points[i + 1].getX()) /
                             ((1 - t) * points[i].getWeight() + t * points[i + 1].getWeight());

            const double y = ((1 - t) * points[i].getWeight() * points[i].getY() +
                              t * points[i + 1].getWeight() * points[i + 1].getY()) /
                             ((1 - t) * points[i].getWeight() + t * points[i + 1].getWeight());
            const double w = 1;
            result.push_back({x, y, w});
        }
        return result;
    }

    RationalBezierPoint DeCasteljauAlgorithm::calculatePoint(const vector<RationalBezierPoint> &points, double t) {
        vector<Point> result = points;
        while (result.size() > 1) {
            result = DeCasteljauAlgorithm::algorithmStep(result, t);
        }

        return result[0];
    }

    std::vector<RationalBezierPoint>
    DeCasteljauAlgorithm::generateCurvePoints(const vector<RationalBezierPoint> &points, double step) {
        vector<Point> result;
        for (double t = 0; t <= 1; t += step) {
            result.emplace_back(DeCasteljauAlgorithm::calculatePoint(points, t));
        }
        return result;
    }
} // CurveLib