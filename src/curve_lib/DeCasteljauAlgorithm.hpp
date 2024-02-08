#ifndef CAGD_RATIONAL_BEZIER_DECASTELJAUALGORITHM_HPP
#define CAGD_RATIONAL_BEZIER_DECASTELJAUALGORITHM_HPP

#include <vector>
#include "RationalBezierPoint.hpp"

using Point = CurveLib::RationalBezierPoint;
using std::vector;

namespace CurveLib {

    /**
     * Provides functions which implement de Casteljau's algorithm.
     */
    class DeCasteljauAlgorithm {
    public:
        /**
         * Generates a rational bezier curve points with a set precision. // TODO: Reword this
         * @param points Base points
         * @param step Precision
         * @return
         */
        static std::vector<RationalBezierPoint>
        generateCurvePoints(const std::vector<RationalBezierPoint> &points, double step);

    public:
        // TODO: Add docs
        static RationalBezierPoint calculatePoint(const std::vector<RationalBezierPoint> &points, double t);

        // TODO: Add docs
        static vector<Point> algorithmStep(const std::vector<RationalBezierPoint> &points, double t);
    };

} // CurveLib

#endif //CAGD_RATIONAL_BEZIER_DECASTELJAUALGORITHM_HPP
