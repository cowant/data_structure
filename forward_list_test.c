#include "forward_list.h"
#include "unit_test.h"
#include <stdio.h>

void Traversal(ForwardList flist) {
  printf("#遍历链表: ");
  for (; flist; flist = flist->next_) {
    printf("%d ", flist->element_);
  }
  printf("#\n");
}

void TESTConstruct() {
  COLORFULMSG("构造一个有10个元素的链表");
  ForwardList flist1 = Construct(10,1,2,3,4,5,6,7,8,9,10);
  if (Empty(flist1)) {
    printf("flist1: no element inserted\n");
  }
  Traversal(flist1);
  Destruct(flist1);
  flist1 = NULL;

  COLORFULMSG("构造空链表");
  ForwardList flist2 = Construct(0);
  if (Empty(flist2)) {
    printf("flist2: no element inserted\n");
  }

  Traversal(flist2);
  Destruct(flist2);
  flist2 = NULL;
}

void TESTPushFront() {
  COLORFULMSG("往空链表插入数据");
  ForwardList flist1 = Construct(0);
  PushFront(&flist1,0);
  PushFront(&flist1,1);
  PushFront(&flist1,2);
  PushFront(&flist1,3);

  Traversal(flist1);
  Destruct(flist1);
  flist1 = NULL;

  COLORFULMSG("往已有链表插入数据");
  ForwardList flist2 = Construct(3, 1, 2, 3);
  PushFront(&flist2, 1);
  PushFront(&flist2, 2);
  PushFront(&flist2, 3);

  Traversal(flist2);
  Destruct(flist2);
  flist2 = NULL;
}

int main() {
  TESTConstruct();
  TESTPushFront();

  return 0;
}
