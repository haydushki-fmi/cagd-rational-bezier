#ifndef CAGD_RATIONAL_BEZIER_RATIONALBEZIERPOINT_HPP
#define CAGD_RATIONAL_BEZIER_RATIONALBEZIERPOINT_HPP

namespace CurveLib {

    /**
     * Represents a point from a rational Bezier curve in 2D space.
     */
    class RationalBezierPoint {
    public:
        RationalBezierPoint(double x, double y, double weight);

        [[nodiscard]] double getX() const;

        [[nodiscard]] double getY() const;

        [[nodiscard]] double getWeight() const;

    private:
        double x;
        double y;
        double weight;
    };

} // CurveLib

#endif //CAGD_RATIONAL_BEZIER_RATIONALBEZIERPOINT_HPP
