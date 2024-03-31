add_executable(color_test color_test.cpp)
target_link_libraries(color_test PRIVATE GTest::gtest_main color)
gtest_discover_tests(color_test)

