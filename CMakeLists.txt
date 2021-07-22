cmake_minimum_required(VERSION 3.0.0)
project(Bowling)

add_subdirectory(tests)

enable_testing()
add_test(NAME MyTests COMMAND ScoreTests)
