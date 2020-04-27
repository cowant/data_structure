// 使用gtest测试框架测试

#include <iostream>
#include "gtest/gtest.h"
#include "forward_list.h"
#include <stdio.h>

TEST(Construct, ForwardList) {
  ForwardList flist = Construct(10,1,2,3,4,5,6,7,8,9,10);
  ASSERT_FALSE(Empty(flist));

  for(int i = 1; i <= 10; i++) {
    ASSERT_EQ(flist->element_, i);
    flist = flist->next_;
  }
  Destruct(&flist);
}

TEST(PushFront, ForwardList) {
  ForwardList flist = Construct(0);
  PushFront(&flist,0);
  PushFront(&flist,1);
  PushFront(&flist,2);
  PushFront(&flist,3);

  for (int i = 0; i < 4; i++) {
    ASSERT_EQ(Front(flist),flist->element_);
    PopFront(&flist);
  }

  Destruct(&flist);
}

TEST(PopFront, ForwardList) {
  // 空链表PopFront会发生段错误
  ForwardList flist = Construct(0);
  ASSERT_DEATH(PopFront(&flist), "");
  Destruct(&flist);

  flist = Construct(1, 1);
  PopFront(&flist);
  ASSERT_TRUE(Empty(flist));
  Destruct(&flist);

  flist = Construct(4, 1, 3, 7, 11);
  for (int i = 0; i < 4; i++) {
    ASSERT_EQ(Front(flist),flist->element_);
    PopFront(&flist);
  }
  Destruct(&flist);
}

TEST(InsertAfter, ForwardList) {
  // InsertAfter构造一条新链表
  ForwardList flist = NULL;
  Iterator iter = BeforeBegin(&flist);
  for (int i = 0; i < 10; ++i) {
    iter = InsertAfter(&flist, iter, i);
  }

  auto current = flist;
  for (int i = 0; i < 10; i++) {
    ASSERT_EQ(Front(current), current->element_);
    current = current->next_;
  }
  Destruct(&flist);

  // 如果是一个空链表，在Begin位置调用InsertAfter将
  // 发生段错误
  flist = Construct(0);
  ASSERT_DEATH(InsertAfter(&flist, Begin(&flist), 1), "");
  Destruct(&flist);
}

TEST(EraseAfter, ForwardList) {
  // 单节点链表必须使用BeforeBegin获取迭代器才能调用
  // EraseAfter，不然就crash
  ForwardList flist = Construct(1, 20);
  ASSERT_DEATH(EraseAfter(&flist, Begin(&flist)), "");
  Destruct(&flist);

  // 单链表节点EraseAfter的正确姿势
  flist = Construct(1, 10);
  EraseAfter(&flist, BeforeBegin(&flist));
  ASSERT_TRUE(Empty(flist));
  Destruct(&flist);

  // 用EraseAfter销毁整个链表
  flist = Construct(2, 1, 2);
  Node* p = EraseAfter(&flist, Begin(&flist));
  ASSERT_EQ(Front(flist), 1);
  ASSERT_EQ(p, nullptr);
  Destruct(&flist);

  // 用EraseAfter销毁整个链表
  flist = Construct(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  while (flist) {
    flist = EraseAfter(&flist, BeforeBegin(&flist));
  }
  ASSERT_TRUE(Empty(flist));
  Destruct(&flist);
}

TEST(Remove, ForwardList) {
  ForwardList flist = Construct(1, 10);
  Remove(&flist, 10);
  ASSERT_TRUE(Empty(flist));
  Destruct(&flist);

  flist = Construct(0);
  Remove(&flist, 1);
  Destruct(&flist);

  flist = Construct(4, 1, 2, 3, 4);

  Remove(&flist, 1);
  ASSERT_EQ(Front(flist), 2);

  Remove(&flist, 2);
  ASSERT_EQ(Front(flist), 3);

  Remove(&flist, 3);
  ASSERT_EQ(Front(flist), 4);

  Remove(&flist, 4);
  ASSERT_TRUE(Empty(flist));
  Destruct(&flist);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
