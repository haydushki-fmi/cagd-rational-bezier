add_library(curve_lib)

target_sources(
        curve_lib
        PRIVATE
        RationalBezierPoint.hpp
        RationalBezierPoint.cpp
        DeCasteljauAlgorithm.hpp
        DeCasteljauAlgorithm.cpp
)