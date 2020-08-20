// 使用gtest测试框架测试

#include <iostream>
#include "gtest/gtest.h"
#include "forward_list.h"
#include <stdio.h>


TEST(FLInsert, ForwardList) {
  ForwardList flist = NULL;
  flist = FLInsert(flist, 10);
  flist = FLInsert(flist, 20);
  flist = FLInsert(flist, 30);
  flist = FLInsert(flist, 40);
  flist = FLInsert(flist, 50);

  ASSERT_EQ(flist->element, 50);
  ASSERT_EQ(flist->next->element, 40);
  ASSERT_EQ(flist->next->next->element, 30);
  ASSERT_EQ(flist->next->next->next->element, 20);
  ASSERT_EQ(flist->next->next->next->next->element, 10);
}

TEST(FLErase, ForwardList) {
  ForwardList flist = NULL;

  flist = FLErase(flist, 0);
  ASSERT_TRUE(flist == NULL);

  flist = FLInsert(flist, 10);
  flist = FLInsert(flist, 20);
  flist = FLInsert(flist, 30);
  flist = FLInsert(flist, 40);
  flist = FLInsert(flist, 50);

  flist = FLErase(flist, 30);
  flist = FLErase(flist, 50);
  ASSERT_EQ(flist->element, 40);
  ASSERT_EQ(flist->next->element, 20);
  ASSERT_EQ(flist->next->next->element, 10);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
