
// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"
TEST(Example, Stack) {
    EXPECT_EQ(std::is_move_constructible<stack<int>>::value, true);
    EXPECT_EQ(std::is_move_assignable<stack<int>>::value, true);
    EXPECT_EQ(std::is_copy_constructible<stack<int>>::value, false);
    EXPECT_EQ(std::is_copy_assignable<stack<int>>::value, false);
    stack <std::string> x;
    x.push("hi");
    x.push("msi");
    x.push("rin");
    EXPECT_EQ((std::string) x.pop(), "rin");
    dog Lavr;
    stack<dog> st;
    st.push(Lavr);
    st.push_emplace("world");
    EXPECT_EQ(st.head().word, "world");
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
