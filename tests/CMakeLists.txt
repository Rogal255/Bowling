add_library(${PROJECT_NAME}-catch STATIC catch.cpp)
set_target_properties(${PROJECT_NAME}-catch PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

add_executable(CatchMain CatchMain.cpp)
set_target_properties(CatchMain PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

add_executable(ScoreTests ScoreTests.cpp)
set_target_properties(CatchMain PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED ON)

target_link_libraries(CatchMain PRIVATE ${PROJECT_NAME}-catch)
target_link_libraries(ScoreTests PRIVATE ${PROJECT_NAME}-catch)
