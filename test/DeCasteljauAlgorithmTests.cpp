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
        points.emplace_back(0, 0, 1);
        points.emplace_back(0, 1, 1);
        double t = 0.5;

        auto result = Algorithm::algorithmStep(points, t);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == Point(0, 0.5, 1));
    }

    SECTION("Different weights, 2 points") {
        vector<Point> points;
        points.emplace_back(0, 0, 1);
        points.emplace_back(0, 1, 2);
        double t = 0.5;

        auto result = Algorithm::algorithmStep(points, t);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == Point(0, (2.0 / 3), 1));
    }
}

TEST_CASE("Algorithm reduces points to a single point for a given t") {
    SECTION("All weights = 1") {
        vector<Point> points;
        points.emplace_back(0, 0, 1);
        points.emplace_back(0.5, 1, 1);
        points.emplace_back(1, 0, 1);

        auto result = Algorithm::calculatePoint(points, 0.5);

        REQUIRE(result == Point(0.5, 0.5, 1));
    }

    SECTION("Different weights") {
        vector<Point> points;
        points.emplace_back(0, 0, 1);
        points.emplace_back(0.5, 1, 2);
        points.emplace_back(1, 0, 1);

        auto result = Algorithm::calculatePoint(points, 0.5);

        REQUIRE(result == Point(0.5, 2.0 / 3, 1));
    }
}

TEST_CASE("Algorithm calculates curve points for a desired step") {
    vector<Point> points;
    points.emplace_back(0, 0, 1);
    points.emplace_back(0.5, 1, 2);
    points.emplace_back(1, 0, 1);

    auto result = Algorithm::generateCurvePoints(points, 0.25);

    REQUIRE(result.size() == 5);
    REQUIRE(result[0] == points[0]);
    REQUIRE(result[2] == Point(0.5, 2.0 / 3, 1));
    REQUIRE(result[4] == points[2]);
}