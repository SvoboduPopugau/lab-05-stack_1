#include <gtest/gtest.h>
#include "Stack_object.h"

TEST(Stack_object, Constructors) {
  int x = 14;
  int y = 19;
  auto s_1 = Stack_object<int>(x);
  auto s_2 = Stack_object<int>(std::move(y));
  EXPECT_EQ(s_1.GetValue(), 14);
  EXPECT_EQ(s_2.GetValue(), 19);
  s_1.SetPrevious(&s_2);
  EXPECT_EQ(s_1.GetPrevious(), &s_2);
  EXPECT_EQ(s_2.GetPrevious(), nullptr);
}
