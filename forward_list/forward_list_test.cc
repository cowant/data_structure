// 使用gtest测试框架测试

#include "gtest/gtest.h"
#include "forward_list.h"
#include <stdio.h>

void Traversal(ForwardList flist) {
  printf("#遍历链表: ");
  for (; flist; flist = flist->next_) {
    printf("%d ", flist->element_);
  }
  printf("#\n");
}

TEST(Construct, Construct) {
  ForwardList flist1 = Construct(10,1,2,3,4,5,6,7,8,9,10);
  ASSERT_FALSE(Empty(flist1));
}

//void TESTPushFront() {
//  COLORFULMSG("往空链表插入数据");
//  ForwardList flist1 = Construct(0);
//  PushFront(&flist1,0);
//  PushFront(&flist1,1);
//  PushFront(&flist1,2);
//  PushFront(&flist1,3);
//
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//
//  COLORFULMSG("往已有链表插入数据");
//  ForwardList flist2 = Construct(3, 1, 2, 3);
//  PushFront(&flist2, 1);
//  PushFront(&flist2, 2);
//  PushFront(&flist2, 3);
//
//  Traversal(flist2);
//  Destruct(flist2);
//  flist2 = NULL;
//}
//
//void TESTPopFront() {
//  COLORFULMSG("空链表PopFront");
//  ForwardList flist1 = Construct(0);
//  PopFront(&flist1);
//
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//
//  COLORFULMSG("已有链表PopFront");
//  ForwardList flist2 = Construct(4, 1, 2, 3, 4);
//  Traversal(flist2);
//
//  PopFront(&flist2);
//  Traversal(flist2);
//
//  PopFront(&flist2);
//  Traversal(flist2);
//
//  PopFront(&flist2);
//  Traversal(flist2);
//
//  PopFront(&flist2);
//  Traversal(flist2);
//
//  Destruct(flist2);
//  flist2 = NULL;
//}
//
//void TESTInsertAfter() {
//  COLORFULMSG("使用InsertAfter构建新链表");
//  // 定义一条空链表
//  ForwardList flist = NULL;
//  Iterator iter = BeforeBegin(&flist);
//  for (int i = 0; i < 10; ++i) {
//    iter = InsertAfter(&flist, iter, i);
//  }
//  Traversal(flist);
//  Destruct(flist);
//  flist = NULL;
//}
//
//void TESTEraseAfter() {
//  COLORFULMSG("使用EraseAfter删除指定节点的后继节点: 单节点链表");
//  ForwardList flist1 = Construct(1, 10);
//  EraseAfter(&flist1, BeforeBegin(&flist1));
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//
//  COLORFULMSG("使用EraseAfter删除指定节点的后继节点: 多节点链表");
//  ForwardList flist2 = Construct(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
//  EraseAfter(&flist2, BeforeBegin(&flist2));
//  Traversal(flist2);
//  Destruct(flist2);
//  flist2 = NULL;
//
//  COLORFULMSG("使用EraseAfter删除指定节点的后继节点: 单节点链表");
//  ForwardList flist3 = Construct(1, 10);
//  EraseAfter(&flist3, Begin(&flist3));
//  Traversal(flist3);
//  Destruct(flist3);
//  flist3 = NULL;
//}
//
//void TESTEraseAfterCrash() {
//  COLORFULMSG("使用EraseAfter删除指定节点的后继节点: 单节点链表");
//  ForwardList flist1 = Construct(1, 10);
//  // 单节点链表必须使用BeforeBegin获取迭代器才能调用
//  // EraseAfter，不然就crash
//  EraseAfter(&flist1, Begin(&flist1));
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//}
//
//void TESTRemove() {
//  COLORFULMSG("使用Remove删除指定值的节点: 只有一个节点");
//  ForwardList flist1 = Construct(1, 10);
//  Remove(&flist1, 10);
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//
//  COLORFULMSG("使用Remove删除指定值的节点: 空链表");
//  flist1 = Construct(0);
//  Remove(&flist1, 1);
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//
//  COLORFULMSG("使用Remove删除指定值的节点: 4个元素删除首节点");
//  flist1 = Construct(4, 1, 2, 3, 4);
//  Remove(&flist1, 1);
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//
//  COLORFULMSG("使用Remove删除指定值的节点: 4个元素删除尾节点");
//  flist1 = Construct(4, 1, 2, 3, 4);
//  Remove(&flist1, 4);
//  Traversal(flist1);
//  Destruct(flist1);
//  flist1 = NULL;
//}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
