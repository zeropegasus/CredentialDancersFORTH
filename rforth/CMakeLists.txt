FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        int_stack_tests
        int_stack_tests.cc
        int_stack.c
)
add_executable(
	R-FORTH
	main.c token.c int_stack.c)
	
target_link_libraries(
        int_stack_tests
        gtest_main
        -lpthread
)
include(GoogleTest)
gtest_discover_tests(int_stack_tests)