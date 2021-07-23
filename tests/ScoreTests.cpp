#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "../src/Score.hpp"
#include "catch.hpp"

SCENARIO("Final score check", "[Score][Bowls]") {
    using CorrectArray = std::array<std::pair<std::array<std::pair<uint8_t, uint8_t>, 11>, uint16_t>, 9>;
    CorrectArray arr1{{
        {{{{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 10}}}, 300},
        {{{{9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {0, 0}}}, 90},
        {{{{5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 0}}}, 150},
        {{{{10, 0}, {7, 3}, {9, 0}, {10, 0}, {0, 8}, {8, 2}, {0, 6}, {10, 0}, {10, 0}, {10, 0}, {8, 1}}}, 167},
        {{{{8, 0}, {7, 0}, {5, 3}, {9, 1}, {9, 1}, {10, 0}, {8, 0}, {5, 1}, {3, 7}, {9, 0}, {0, 0}}}, 122},
        {{{{8, 2}, {9, 0}, {4, 4}, {7, 2}, {9, 0}, {10, 0}, {10, 0}, {8, 0}, {3, 5}, {9, 1}, {7, 0}}}, 133},
        {{{{8, 2}, {5, 4}, {9, 0}, {10, 0}, {10, 0}, {5, 5}, {5, 3}, {6, 3}, {9, 1}, {9, 1}, {10, 0}}}, 149},
        {{{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}}, 0},
        {{{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 5}, {0, 0}}}, 5},
    }};

    for (uint8_t testCaseNo = 0; testCaseNo < arr1.size(); ++testCaseNo) {
        Score scores;
        for (uint8_t frame = 0; frame < arr1[testCaseNo].first.size(); ++frame) {
            scores.addResult(arr1[testCaseNo].first[frame].first);
            scores.addResult(arr1[testCaseNo].first[frame].second);
        }
        GIVEN(scores.resultsToString()) {
            WHEN("Score class is filled with correct arguments") {
                THEN("Final score should be " + std::to_string(arr1[testCaseNo].second)) {
                    CHECK(scores.getFinalScore() == arr1[testCaseNo].second);
                }
            }
        }
    }
}
