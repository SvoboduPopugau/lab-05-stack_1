#include <gtest/gtest.h>
#include "Stack_2.h"
#include "Stack_1.h"

struct Example{
 public:
  Example(int i, int j, int m){
      val_1 = i;
      val_2 = j;
      val_3 = m;
  };
//  explicit Example(Example& value) = delete;
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

Stack_1<int> my_function_1(){
  auto x = Stack_1<int>();
  x.push(10);
  x.push(23);
  return x;
}


TEST(Stack_2Creating, Constructors) {
  Stack_2<int> first;
  EXPECT_THROW(first.head(), std::runtime_error);
  int x = 10;
  first.push(std::move(x));
  Stack_2<int> second(std::move(first));
  EXPECT_EQ(second.head(),x);
}
TEST(Stack_2Pushing, Push){  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Stack_1<Example> first;
  Example x (1,2,3);
  Example y (4, 5,6);
//  int x = 1;
//  int y = 2;
  first.push(std::move(x));
  first.push(std::move(y));
  EXPECT_EQ(first.head(), y);
}
TEST(Stack_2Pushing, Push_emplace){  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  Stack_2<Example> first;
  first.push_emplace(1, 2, 4);
  first.push_emplace(3,5,6);
}