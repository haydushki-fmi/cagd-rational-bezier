#ifndef CAGD_RATIONAL_BEZIER_RATIONALBEZIERPOINT_HPP
#define CAGD_RATIONAL_BEZIER_RATIONALBEZIERPOINT_HPP

namespace CurveLib {

    /**
     * Represents a point from a rational Bezier curve in 2D space.
     */
    class RationalBezierPoint {
    public:
        RationalBezierPoint(double x, double y, double weight);

        bool operator==(const RationalBezierPoint &rhs) const;

        bool operator!=(const RationalBezierPoint &rhs) const;

        [[nodiscard]] double getX() const;

        [[nodiscard]] double getY() const;

        [[nodiscard]] double getWeight() const;

        void setX(double x);

        void setY(double y);

        void setWeight(double weight);

    private:
        double x;
        double y;
        double weight;
    };

} // CurveLib

#endif //CAGD_RATIONAL_BEZIER_RATIONALBEZIERPOINT_HPP
