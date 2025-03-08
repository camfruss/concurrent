
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)

find_package(GTest CONFIG REQUIRED)

add_executable(tests 
	rwlock_tests.cpp
)
target_link_libraries(
	tests 
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

