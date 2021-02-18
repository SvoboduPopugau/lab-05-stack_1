#include <gtest/gtest.h>
#include "Stack_1.h"

Stack_1<int> my_function(){
  auto x = Stack_1<int>();
  x.push(10);
  x.push(23);
  return x;
}

TEST(Stack_1Creating, Constuctors) {
  Stack_1<int> first;
  EXPECT_THROW(first.head(), std::runtime_error);
  auto second = Stack_1<int>(my_function());
  EXPECT_EQ(second.head(), 23);
}
TEST(Stack_1Pushing, ForRvalue){
  int x = 13;
  int y = 78;
  Stack_1<int> first;
  first.push(std::move(x));
  EXPECT_EQ(first.head(), 13);
  first.push(std::move(y));
  EXPECT_EQ(first.head(), 78);
}
TEST(Stack_1Pushing, ForLvalue){
  int x = 13;
  int y = 78;
  Stack_1<int> first;
  first.push(x);
  EXPECT_EQ(first.head(), 13);
  first.push(y);
  EXPECT_EQ(first.head(), 78);
}
TEST(Stack_1Poping, PopMethod){
  Stack_1<int> first(my_function());
  EXPECT_EQ(first.head(), 23);
  first.pop();
  EXPECT_EQ(first.head(), 10);
  first.pop();
  EXPECT_THROW(first.pop(), std::runtime_error);
}