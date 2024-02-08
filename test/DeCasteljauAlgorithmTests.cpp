#include "catch2/catch_all.hpp"
#include "curve_lib/RationalBezierPoint.hpp"
#include "curve_lib/DeCasteljauAlgorithm.hpp"

using Point = CurveLib::RationalBezierPoint;
using Algorithm = CurveLib::DeCasteljauAlgorithm;
using std::vector;

TEST_CASE("Algorithm step works as expected") {
    // TODO: Test with different X values
    SECTION("Equal weights, 2 points") {
        vector<Point> points;
        points.push_back({0, 0, 1});
        points.push_back({0, 1, 1});
        double t = 0.5;

        auto result = Algorithm::algorithmStep(points, t);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == Point(0, 0.5, 1));
    }

    SECTION("Different weights, 2 points") {
        vector<Point> points;
        points.push_back({0, 0, 1});
        points.push_back({0, 1, 2});
        double t = 0.5;

        auto result = Algorithm::algorithmStep(points, t);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == Point(0, (2.0 / 3), 1));
    }
}