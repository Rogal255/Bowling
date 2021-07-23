#include "Score.hpp"
#include <iostream>

void Score::addResult(uint8_t throwResult) {
    if (frameEnd == false) {
        result_[currentFrame_].first = throwResult;
        frameEnd = true;
    } else {
        result_[currentFrame_].second = throwResult;
        frameEnd = false;
        ++currentFrame_;
    }
}

uint16_t Score::getFinalScore() {
    return 0;
}

std::string Score::resultsToString() {
    std::string str;
    for (uint8_t ture = 0; ture < currentFrame_; ++ture) {
        if (ture == bonusTurn) {
            if (result_[bonusTurn - 1].first + result_[bonusTurn - 1].second != maxOneThrowPoints_) {
                return str;
            } else if (result_[bonusTurn - 1].first == maxOneThrowPoints_) {
                    str += throwResultToString(bonusTurn, 1) + throwResultToString(bonusTurn, 2);
                    return str;
                }
            else {
                str += throwResultToString(bonusTurn, 1);
                return str;
            }
        }
        str += throwResultToString(ture, 1);
        if (result_[ture].first != maxOneThrowPoints_) {
                str += throwResultToString(ture, 2);
        }
        if (ture == bonusTurn - 1) {
            str += "||";
        } else if (ture < bonusTurn) {
            str += '|';
        }
        for (uint8_t ture = currentFrame_; ture < result_.size(); ++ture) {
            str += "  ";
            if (ture == bonusTurn - 1) {
                str += "||";
            } else if (ture < bonusTurn - 1) {
                str += '|';
            }
        }
    }
    return str;
}

std::string Score::throwResultToString(uint8_t ture, uint8_t throwInTurn) {
    if (throwInTurn == 1) {
        if (result_[ture].first == maxOneThrowPoints_) {
            return "X";
        } else if (result_[ture].first == 0) {
            return "-";
        } else {
            return std::to_string(result_[ture].first);
        }
    } else {
        if (result_[ture].second == maxOneThrowPoints_ && ture == bonusTurn) {
            return "X";
        }
        if (result_[ture].second == maxOneThrowPoints_) {
            return "/";
        }
        if (result_[ture].first + result_[ture].second == maxOneThrowPoints_) {
            return "/";
        }
        if (result_[ture].second == 0) {
            return "-";
        }
        return std::to_string(result_[ture].second);
    }
}
