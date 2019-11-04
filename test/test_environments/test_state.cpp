#include <State.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

struct BasicStruct {
    BasicStruct(int val, std::string str1) : intVal(val), stringVal(str1) {}

  public:
    std::string stringVal;
    int intVal;
};

TEST(State, TestVariableInput) {
    // Arange
    std::vector<int> someVec = {1, 2, 3, 4};
    BasicStruct someStruct = BasicStruct(10, "test");

    // Act and Assert
    EXPECT_NO_FATAL_FAILURE(State(1));
    EXPECT_NO_FATAL_FAILURE(State("1"));
    EXPECT_NO_FATAL_FAILURE(State vecState = State(someVec));
    EXPECT_NO_FATAL_FAILURE(State structState = State(someStruct));
}

TEST(State, TestInputHandling) {
    // Arange
    int originVal = 10;

    // Act
    State stateWithVal = State(originVal);

    // Assert
    int stateVal = stateWithVal.getData<int>();
    EXPECT_EQ(originVal, stateVal);
}