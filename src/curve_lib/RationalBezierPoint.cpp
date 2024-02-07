#include "RationalBezierPoint.hpp"

namespace CurveLib {
    RationalBezierPoint::RationalBezierPoint(double x, double y, double weight) : x(x), y(y), weight(weight) {}

    double RationalBezierPoint::getX() const {
        return x;
    }

    double RationalBezierPoint::getY() const {
        return y;
    }

    double RationalBezierPoint::getWeight() const {
        return weight;
    }
} // CurveLib