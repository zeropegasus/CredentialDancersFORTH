//
// tests for int_stack operations.
//

#include <gtest/gtest.h>
#include "int_stack.hh"

TEST(IntStackTests, Initialization) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    ASSERT_EQ(int_stack_size(&stack), 0);
    ASSERT_EQ(int_stack_capacity(&stack), 10);
}

TEST(IntStackTests, PushToCapacityAndOverflow) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(int_stack_push(&stack, i));
    }
    ASSERT_FALSE(int_stack_push(&stack, 11)); // Test overflow
}

TEST(IntStackTests, PushToCapacityPopUntilUnderflow) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    for (int i = 0; i < 10; i++) {
        ASSERT_TRUE(int_stack_push(&stack, i));
    }
    int value;
    for (int i = 9; i >= 0; i--) {
        ASSERT_TRUE(int_stack_pop(&stack, &value));
        ASSERT_EQ(value, i);
    }
    ASSERT_FALSE(int_stack_pop(&stack, &value)); // Test underflow
}

TEST(IntStackTests, TopValue) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 5);
    int value;
    ASSERT_TRUE(int_stack_top(&stack, &value));
    ASSERT_EQ(value, 5);
}

TEST(IntStackTests, DuplicateTop) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 5);
    ASSERT_TRUE(int_stack_dup(&stack));
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 5);
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 5);
}

TEST(IntStackTests, SwapTopTwo) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    ASSERT_TRUE(int_stack_swap(&stack));
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1);
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 2);
}

TEST(IntStackTests, CopySecondItemToTop) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    ASSERT_TRUE(int_stack_over(&stack));
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1);
}

TEST(IntStackTests, RotateTopThree) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1); // Bottom of the three
    int_stack_push(&stack, 2); // Middle
    int_stack_push(&stack, 3); // Top

    ASSERT_TRUE(int_stack_rot(&stack));

    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1); // Now on top after rotation

    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 3); // Now in the middle

    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 2); // Now at the bottom
}

TEST(IntStackTests, DropTop) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    ASSERT_TRUE(int_stack_drop(&stack));
    ASSERT_EQ(int_stack_size(&stack), 1); // Size should decrease by 1
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1); // Verify that 2 was dropped
}

TEST(IntStackTests, SwapTopTwoPairs) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    int_stack_push(&stack, 3);
    int_stack_push(&stack, 4);
    ASSERT_TRUE(int_stack_2swap(&stack));
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 2); // After swap, 2 is top
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1); // Then 1
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 4); // Then 4 (swapped)
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 3); // Then 3 (swapped)
}

TEST(IntStackTests, DuplicateTopTwo) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    ASSERT_TRUE(int_stack_2dup(&stack));
    ASSERT_EQ(int_stack_size(&stack), 4); // Size should double
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 2); // Duplicated values on top
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1); // Duplicated values on top
}


TEST(IntStackTests, TwoOverOperation) {
    int_stack_t stack;
    int_stack_init(&stack, 10);

    // Setup stack with at least four elements
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    int_stack_push(&stack, 3);
    int_stack_push(&stack, 4);

    // Perform 2OVER operation
    ASSERT_TRUE(int_stack_2over(&stack));

    // Assert the stack now contains the correct elements after 2OVER
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1);
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 2); 

    // Cleanup by popping remaining elements (not shown)
}
TEST(IntStackTests, Subtraction) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 5);
    int_stack_push(&stack, 3);
    int_stack_sub(&stack);
    int result;
    int_stack_pop(&stack, &result);
    ASSERT_EQ(result, 2);
}
TEST(IntStackTests, Multiplication) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 4);
    int_stack_push(&stack, 5);
    int_stack_mul(&stack);
    int result;
    int_stack_pop(&stack, &result);
    ASSERT_EQ(result, 20);
}
TEST(IntStackTests, Division) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 2);
    int_stack_div(&stack);
    int result;
    int_stack_pop(&stack, &result);
    ASSERT_EQ(result, 5);
}
TEST(IntStackTests, DivMod) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 3);
    int_stack_divmod(&stack);
    int quotient, remainder;
    int_stack_pop(&stack, &quotient);
    int_stack_pop(&stack, &remainder);
    ASSERT_EQ(remainder, 1);
    ASSERT_EQ(quotient, 3);
}
TEST(IntStackTests, Modulus) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 3);
    int_stack_mod(&stack);
    int result;
    int_stack_pop(&stack, &result);
    ASSERT_EQ(result, 1);
}



TEST(IntStackTests, DropTopTwo) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    int_stack_push(&stack, 3);
    ASSERT_TRUE(int_stack_2drop(&stack));
    ASSERT_EQ(int_stack_size(&stack), 1); // Size decreases by 2
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 1); // Verify remaining value
}

TEST(IntStackTests, AddTopTwoValues) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int_stack_push(&stack, 1);
    int_stack_push(&stack, 2);
    ASSERT_TRUE(int_stack_add(&stack));
    ASSERT_EQ(int_stack_size(&stack), 1); // Size decreases by 1 after add
    int value;
    int_stack_pop(&stack, &value);
    ASSERT_EQ(value, 3); // Verify addition result
}



// Edge Case Tests
TEST(IntStackTests, EmptyStackOperations) {
    int_stack_t stack;
    int_stack_init(&stack, 10);
    int value;
    ASSERT_FALSE(int_stack_pop(&stack, &value)); // Pop from empty
    ASSERT_FALSE(int_stack_top(&stack, &value)); // Top from empty
    ASSERT_FALSE(int_stack_dup(&stack)); // Dup on empty
    ASSERT_FALSE(int_stack_swap(&stack)); // Swap on empty
}

TEST(IntStackTests, CapacityLimits) {
    int_stack_t stack;
    int_stack_init(&stack, 2);
    ASSERT_TRUE(int_stack_push(&stack, 1));
    ASSERT_TRUE(int_stack_push(&stack, 2));
    ASSERT_FALSE(int_stack_push(&stack, 3)); // Push beyond capacity
    int value;
    ASSERT_TRUE(int_stack_pop(&stack, &value)); // Pop to make space
    ASSERT_TRUE(int_stack_push(&stack, 3)); // Push should succeed now
}

//boolean tests
TEST(IntStackTests, GreaterThan) {
    int_stack_t stack;
    int_stack_init(&stack, 10);

    int_stack_push(&stack, 5);
    int_stack_push(&stack, 10);
    int_stack_greater_than(&stack); // Should evaluate to false (0)

    int result;
    int_stack_pop(&stack, &result);
    ASSERT_EQ(result, 0); // 5 is not greater than 10
}

TEST(IntStackTests, Equals) {
    int_stack_t stack;
    int_stack_init(&stack, 10);

    int_stack_push(&stack, 10);
    int_stack_push(&stack, 10);
    int_stack_equals(&stack); // Should evaluate to true (1)

    int result;
    int_stack_pop(&stack, &result);
    ASSERT_EQ(result, 1); // 10 equals 10
}

//variable tests
TEST(IntStackTests, SetAndGetVariable) {
    int_stack_set_var("myVar", 123, 0); // 0 indicates it's a variable

    int value;
    ASSERT_TRUE(int_stack_get_var("myVar", &value));
    ASSERT_EQ(value, 123);
}

TEST(IntStackTests, ModifyConstant) {
    int_stack_set_var("myConst", 456, 1); // 1 indicates it's a constant

    // Attempt to modify the constant
    ASSERT_FALSE(int_stack_set_var("myConst", 789, 1));
    
    // Verify its value remains unchanged
    int value;
    int_stack_get_var("myConst", &value);
    ASSERT_EQ(value, 456);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
