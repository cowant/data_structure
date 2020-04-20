#include "forward_list.h"
#include <stdio.h>

void TESTConstruct() {
  printf("构造一个有10个元素的链表:\n");
  ForwardList flist1 = Construct(10,1,2,3,4,5,6,7,8,9,10);
  if (Empty(&flist1)) {
    printf("flist1: no element inserted\n");
  }

  for (; flist1; flist1 = flist1->next_) {
    printf("%d\n", flist1->element_);
  }

  Destruct(&flist1);

  for (; flist1; flist1 = flist1->next_) {
    printf("%d\n", flist1->element_);
  }

  printf("构造空链表:\n");
  ForwardList flist2 = Construct(0);
  if (Empty(&flist2)) {
    printf("flist2: no element inserted\n");
  }

  for (; flist2; flist2 = flist2->next_) {
    printf("%d\n", flist2->element_);
  }
  Destruct(&flist2);

}

int main() {
  TESTConstruct();

  return 0;
}
