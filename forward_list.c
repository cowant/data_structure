#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <assert.h>
#include "forward_list.h"
#include "unit_test.h"

/*
* 利用二级指针操作链表的要点在于理解链表的实质是一串逻辑上
* 相连的指针变量，而数据只是投靠在这个指针变量上。我们插入
* 删除链表节点时，对应于增加一个指针变量和减少一个指针变
* 量。将链表视为一系列指针变量组成的指针链，那么用二级指针
* 对指针链进行插入/删除操作那就再自然不过了。
*
* 这里的链表有两种含义:
*  1 指针变量组成的指针链，节点为ForwardList类型;
*  2 结构体变量组成的数据链，节点为Node类型。
* 指针链上的节点解引用后得到这个指针指向的数据链节点。
*/


static Node* NewNode(ElementType element) {
  Node *p = malloc(sizeof(Node));
  if (!p) {
    printf("malloc node error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  p->element_ = element;
  p->next_ = NULL;

  return p;
}

// nums: 构造一个有nums个元素的链表。
ForwardList Construct(size_t nums, ...) {
  // flist是指针链的首元素
  ForwardList flist = NULL;
  // current是一个二级指针，它总是指向指针链的尾节点
  ForwardList *current = &flist;

  va_list va;
  va_start(va, nums);
  for (int i = 0; i < nums; i++) {
    ElementType e = va_arg(va, ElementType);
    Node *p = NewNode(e);
    // 将新的指针变量加入指针链的尾部
    *current = p;
    current = &(p->next_);
    PRINT("挂靠链表节点的值: %d\n", e);
  }
  va_end(va);
  return flist;
}

void Destruct(ForwardList flist) {
  while (flist) {
    ForwardList next = flist->next_;
    PRINT("释放节点的值: %d\n",flist->element_);
    free(flist);
    flist = next;
  }
}

Bool Empty(ForwardList flist) {
  if (flist) {
    return FALSE;
  } else {
    return TRUE;
  }
}

// 访问链表的第一个元素
ElementType Front(ForwardList flist) {
  assert(flist);
  return flist->element_;
}

// 在链表头部插入一个新元素
void PushFront(ForwardList *flist, ElementType element) {
  Node *p = NewNode(element);

  ForwardList next = *flist;
  *flist = p;
  p->next_ = next;
}



// 删除链表头部的元素
void PopFront(ForwardList flist);

// 将新值插入指定位置后面
void InsertAfter(ForwardList flist, Position *pos, ElementType element);
