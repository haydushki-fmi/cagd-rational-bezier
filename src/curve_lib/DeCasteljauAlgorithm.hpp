#ifndef CAGD_RATIONAL_BEZIER_DECASTELJAUALGORITHM_HPP
#define CAGD_RATIONAL_BEZIER_DECASTELJAUALGORITHM_HPP

#include <vector>
#include "RationalBezierPoint.hpp"

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
        generateCurvePoints(std::vector<RationalBezierPoint> points, double step);
    };

} // CurveLib

#endif //CAGD_RATIONAL_BEZIER_DECASTELJAUALGORITHM_HPP
