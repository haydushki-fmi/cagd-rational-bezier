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

    bool RationalBezierPoint::operator==(const RationalBezierPoint &rhs) const {
        return this->x == rhs.x &&
               this->y == rhs.y &&
               this->weight == rhs.weight;
    }

    bool RationalBezierPoint::operator!=(const RationalBezierPoint &rhs) const {
        return !(rhs == *this);
    }
} // CurveLib