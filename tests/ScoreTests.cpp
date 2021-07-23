#include <array>
#include <stdexcept>
#include <string>
#include <utility>
#include "../src/Bowls.hpp"
#include "catch.hpp"

SCENARIO("Bowls::calculateResult should calculate result from string with partial results", "[Bowls][Result]") {
    Bowls bowls;

    // An array of valid arguments and correct results
    std::array<std::pair<std::string, size_t>, 9> arr1{{{"X|X|X|X|X|X|X|X|X|X||XX", 300},
                                                        {"9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||", 90},
                                                        {"5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5", 150},
                                                        {"X|7/|9-|X|-8|8/|-6|X|X|X||81", 167},
                                                        {"8-|7-|53|9/|9/|X|8-|51|3/|9-||", 122},
                                                        {"8/|9-|44|72|9-|X|X|8-|35|9/||7", 133},
                                                        {"8/|54|9-|X|X|5/|53|63|9/|9/||X", 149},
                                                        {"--|--|--|--|--|--|--|--|--|--||", 0},
                                                        {"--|--|--|--|--|--|--|--|--|-5||", 5}}};

    for (size_t i = 0; i < arr1.size(); ++i) {
        GIVEN(arr1[i].first) {
            WHEN("Final result is calculated") {
                size_t result = bowls.calculateResult(arr1[i].first);
                THEN("Result should match " + std::to_string(arr1[i].second)) {
                    REQUIRE(result == arr1[i].second);
                }
            }
        }
    }

    // An array of invalid arguments
    std::array<std::string, 11> arr2{{{"X|X|X|X|X|X|Q|X|X|X||XX"},
                                      {"9-|9-|9-|9|9-|9-|9-|9-|9-|9-||"},
                                      {"5/|5/|5/|5/|5/|5/|5/|5/|5/|5/|5"},
                                      {"|7/|9-|X|-8|8/|-6|X|X|X||81"},
                                      {"8-|7-|53|9/|9/|X|8-|51|3/|9-||XX"},
                                      {"8/|9-|44|72|93|X|X|8-|35|9/||7"},
                                      {"8/|54|9-|X|X|5/|53|63|9/|9/||"},
                                      {"8/|54|9-|X|X|5/53|63|9/|9/||"},
                                      {"--|--|--|--|--|--|--|--|--|--||X"},
                                      {"--|-A|--|--|--|--|--|--|--|-5||"},
                                      {"DUPA"}}};

    for (size_t i = 0; i < arr2.size(); ++i) {
        GIVEN(arr2[i]) {
            WHEN("Final result is calculated and invalid argument is passed") {
                THEN("The method should throw an exception") {
                    REQUIRE_THROWS_AS(bowls.calculateResult(arr2[i]), std::invalid_argument);
                }
            }
        }
    }
}
