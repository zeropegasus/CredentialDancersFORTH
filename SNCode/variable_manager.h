#include <gtest/gtest.h>
#include "int_stack.h" // Make sure to include the variable manager header

// Variable Manager Tests
TEST(VariableManagerTests, SetAndGetVariable) {
    varTable_init(); // Initialize the variable table before testing
    var_set("testVar", 100); // Set a variable

    int value = 0;
    ASSERT_TRUE(var_get("testVar", &value)); // Ensure the variable can be retrieved
    ASSERT_EQ(value, 100); // Verify the value is as expected
}

TEST(VariableManagerTests, UpdateVariable) {
    varTable_init(); // It's good practice to reinitialize for isolation
    var_set("updateTest", 200); // Set initial value
    var_set("updateTest", 300); // Update the value

    int value = 0;
    ASSERT_TRUE(var_get("updateTest", &value)); // Check the updated value can be retrieved
    ASSERT_EQ(value, 300); // Verify the update took place
}

TEST(VariableManagerTests, NonExistentVariable) {
    varTable_init(); // Initialize the variable table
    int value = 0;
    ASSERT_FALSE(var_get("nonExistent", &value)); // Attempt to get a non-existent variable
    // No need for an ASSERT_EQ here, as var_get should return false
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}