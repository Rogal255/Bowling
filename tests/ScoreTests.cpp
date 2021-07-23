#include <string>
#include "../src/Bowls.hpp"
#include "catch.hpp"
#include <array>
#include <utility>

SCENARIO("Bowls::calculateResult should calculate final result from string with partial results", "[Bowls][Result]") {
    Bowls bowls;
    std::array<std::pair<std::string, size_t>, 5> arr {std::make_pair("X|X|X|X|X|X|X|X|X|X||XX", 300),
                                                       std::make_pair("9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||", 90),
                                                       std::make_pair("5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5", 150),
                                                       std::make_pair("X|7/|9-|X|-8|8/|-6|X|X|X||81", 167),
                                                       std::make_pair("8-|7-|53|9/|9/|X|8-|51|3/|9-||", 122)};
    for(size_t i = 0; i < arr.size(); ++i) {
        GIVEN(arr[i].first) {
            WHEN("Result is calculated") {
                size_t result = bowls.calculateResult(arr[i].first);
                THEN("Result should match " + std::to_string(arr[i].second)) {
                    REQUIRE(result == arr[i].second);
                }
            }
        }
    }
}
