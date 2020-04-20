#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include "forward_list.h"

// 利用二级指针操作链表的要点在于理解链表的实质是一串逻辑上
// 相连的指针变量，而数据只是投靠在这个指针变量上。我们插入
// /删除链表节点时，对应于增加一个指针变量和减少一个指针变
// 量。将链表视为指针链，那么用二级指针对指针链进行增删改查
// 操作那就再自然不过了。



// nums: 构造一个有nums个元素的链表。
ForwardList Construct(size_t nums, ...) {
  // 指针链上的第一个指针变量，它没有数据投靠
  ForwardList flist = NULL;

  // 用来操作指针链上指针变量的游标
  ForwardList *current = &flist;

  va_list va;
  va_start(va, nums);
  for (int i = 0; i < nums; i++) {
    // 一个指针变量加上投靠的数据，即我们所定义的struct node
    ElementType e = va_arg(va, ElementType);
    Node *p = malloc(sizeof(Node));
    if (!p) {
      printf("malloc node error: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
    p->element_ = e;
    p->next_ = NULL;

    // 将新的指针变量加入指针链中
    *current = p;
    current = &(p->next_);
#if defined(DEBUG)
    printf("[source file: %s, function: %s, line: %d] ###### 挂靠链表节点的值: %d\n", __FILE__, __FUNCTION__, __LINE__, e);
#endif
  }
  va_end(va);
  return flist;
}

void Destruct(ForwardList *flist) {
  Node *head = *flist;
  while (head) {
    Node *next = head->next_;
    free(head);
    head = next;
  }
}

Bool Empty(ForwardList *flist) {
#if defined(DEBUG)
  printf("[source file: %s, function: %s, line: %d] ###### 链表地址: %p\n", __FILE__, __FUNCTION__, __LINE__, *flist);
#endif
  if (*flist) {
    return FALSE;
  } else {
    return TRUE;
  }
}
