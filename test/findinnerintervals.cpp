#include "catch.hpp"
#include "intervals.h"


TEST_CASE("Find inner intervals")
{
    SECTION("Empty tree")
    {
        IntervalTree tree;
        REQUIRE(tree.isEmpty());

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE(result.empty());
    }

    SECTION("Boundary interval")
    {
        IntervalTree tree;

        for (auto interval : Test::boundaryIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::boundaryIntervals().cbegin()));
    }

    SECTION("Outer intervals")
    {
        IntervalTree tree;

        for (auto interval : Test::outerIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE(result.empty());
    }

    SECTION("Outer and boundary intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::outerIntervals(), Test::boundaryIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::boundaryIntervals().cbegin()));
    }

    SECTION("Inner intervals")
    {
        IntervalTree tree;

        for (auto interval : Test::innerIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::innerIntervals().cbegin()));
    }

    SECTION("Inner and boundary intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::innerIntervals(), Test::boundaryIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), intervals.cbegin()));
    }

    SECTION("Outer and inner intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::outerIntervals(), Test::innerIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::innerIntervals().cbegin()));
    }

    SECTION("Left intervals")
    {
        IntervalTree tree;

        for (auto interval : Test::leftIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE(result.empty());
    }

    SECTION("Left and inner intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::leftIntervals(), Test::innerIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::innerIntervals().cbegin()));
    }

    SECTION("Right intervals")
    {
        IntervalTree tree;

        for (auto interval : Test::rightIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE(result.empty());
    }

    SECTION("Right and inner intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::rightIntervals(), Test::innerIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::innerIntervals().cbegin()));
    }

    SECTION("Left overlapping intervals")
    {
        IntervalTree tree;

        for (auto interval : Test::leftOverlappingIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE(result.empty());
    }

    SECTION("Left overlapping and inner intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::leftOverlappingIntervals(), Test::innerIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::innerIntervals().cbegin()));
    }

    SECTION("Right overlapping intervals")
    {
        IntervalTree tree;

        for (auto interval : Test::rightOverlappingIntervals()) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE(result.empty());
    }

    SECTION("Right overlapping and inner intervals")
    {
        IntervalTree tree;

        auto intervals = Test::compositeIntervals(Test::rightOverlappingIntervals(), Test::innerIntervals());

        for (auto interval : intervals) {
            tree.insert(interval);
        }

        auto result = tree.findInnerIntervals(Test::interval());

        REQUIRE_FALSE(result.empty());
        REQUIRE(std::is_permutation(result.cbegin(), result.cend(), Test::innerIntervals().cbegin()));
    }
}