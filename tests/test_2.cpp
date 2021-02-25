#include <gtest/gtest.h>
#include "Stack_2.h"


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

  bool operator==(const Example& value) const{
    if ((val_1 == value.val_1) & (val_2 == value.val_2)
        & (val_3 == value.val_3)){
      return true;
    } else {
      return false;
    }
  }
 public:
  int val_1;
  int val_2;
  int val_3;
};


TEST(Stack_2Creating, Constructors) {
  Stack_2<Example> first;
  EXPECT_THROW(first.head(), std::runtime_error);
  Example x (10,11,12);
  first.push(std::move(x));
  Stack_2<Example> second(std::move(first));
  EXPECT_EQ(second.head(), x);
}
TEST(Stack_2Pushing, Push){
  Stack_2<Example> first;
  Example x (1,2,3);
  Example y (4, 5,6);
  first.push(std::move(x));
  first.push(std::move(y));
  EXPECT_EQ(first.head(), y);
}
TEST(Stack_2Pushing, Push_emplace){
  Stack_2<Example> first;
  first.push_emplace(1, 2, 4);
  first.push_emplace(3,5,6);
  EXPECT_TRUE(first.head().val_1 == 3);
  Example x;
  x = first.pop();
  EXPECT_TRUE(first.head().val_1 == 1);
  EXPECT_TRUE(x.val_2 == 5);
}
TEST(Stack_2Poping, Pop){
  Stack_2<Example> first;
  EXPECT_THROW(first.pop(), std::runtime_error);
}

