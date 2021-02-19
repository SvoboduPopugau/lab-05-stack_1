#include <gtest/gtest.h>
#include "Stack_1.h"

Stack_1<int> my_function(){
  auto x = Stack_1<int>();
  x.push(10);
  x.push(23);
  return x;
}

struct Example{
 public:
  Example(){
    val_3 = 0;
    val_2 = 0;
    val_1 = 0;
  };
  Example(int i, int j, int m){
    val_1 = i;
    val_2 = j;
    val_3 = m;
  };
  explicit Example(Example& value) = delete;
  Example(Example&& value) noexcept {
    val_1 = value.val_1;
    val_2 = value.val_2;
    val_3 = value.val_3;
  }
  auto operator=(Example&& value)  noexcept -> Example&{
    val_1 = value.val_1;
    val_2 = value.val_2;
    val_3 = value.val_3;
    return *this;
  }
  auto operator=(Example& value) -> Example&{
    val_1 = value.val_1;
    val_2 = value.val_2;
    val_3 = value.val_3;
    return *this;
  }
  bool operator==(Example& value) const{
    if ((val_1 == value.val_1) & (val_2 == value.val_2)
        & (val_3 == value.val_3)){
      return true;
    } else {
      return false;
    }
  }
 private:
  int val_1;
  int val_2;
  int val_3;
};




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
