#include <gtest/gtest.h>
#include "Stack_1.h"

//Некопируемый перемещаемый объект
struct Example{
  Example(int value){
    val = value;
  };
  Example (int&& value){
    val = value;
  };
  explicit Example(Example& temp) = delete;
  Example(Example&& temp){
    val = temp.GetVal();
  };
  int& GetVal(){
    return val;
  }
 private:
  int val;
};

Stack_1<int> my_function(){
  auto x = Stack_1<int>();
  x.push(10);
  x.push(23);
  return x;
}

TEST(Creating, Constuctors) {
  auto first = Stack_1<int>();
  try {
    first.head();
  } catch (std::runtime_error& err) {
    std::string errstring = "Stack is empty";
    EXPECT_EQ(err.what(),errstring);
  }
  auto second = Stack_1<int>(my_function());
  EXPECT_EQ(second.head(), 23);
}
TEST(Pushing, ForRvalue){
  int x = 13;
  int y = 78;
  auto first = Stack_1<int>();
  first.push(std::move(x));
  EXPECT_EQ(first.head(), 13);
  first.push(std::move(y));
  EXPECT_EQ(first.head(), 78);
}
TEST(Pushing, ForLvalue){
  int x = 13;
  int y = 78;
  auto first = Stack_1<int>();
  first.push(x);
  EXPECT_EQ(first.head(), 13);
  first.push(y);
  EXPECT_EQ(first.head(), 78);
}
TEST(Poping, PopMethod){
  auto first = Stack_1<int>(my_function());
  EXPECT_EQ(first.head(), 23);
  first.pop();
  EXPECT_EQ(first.head(), 10);
  first.pop();
  try {
    first.pop();
  } catch (std::runtime_error& err) {
    std::string errstring = "Stack is empty";
    EXPECT_EQ(err.what(), errstring);
  }
}