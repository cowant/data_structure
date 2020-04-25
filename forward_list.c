#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <assert.h>
#include "forward_list.h"
#include "unit_test.h"

static Node* NewNode(ElementType element) {
  Node *p = (Node *)malloc(sizeof(Node));
  if (!p) {
    printf("malloc node error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  p->element_ = element;
  p->next_ = NULL;

  return p;
}

// 构建单向链表，返回一个指向链表首节点的指针，完成构造后链表的
// 所有其他操作都要传入这个指针，可以认为它的作用类似文件句柄。
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
    *current = p;
    current = &(p->next_);
    PRINT("新构造的链表节点的值: %d\n", e);
  }
  va_end(va);
  return flist;
}

void Destruct(ForwardList flist) {
  while (flist) {
    ForwardList next = flist->next_;
    PRINT("将要释放的节点的值: %d\n",flist->element_);
    free(flist);
    flist = next;
  }
}

Bool Empty(ForwardList flist) {
  return flist == NULL;
}

// 访问链表的第一个元素
ElementType Front(ForwardList flist) {
  assert(flist);
  return flist->element_;
}

// 向链表头部插入一个节点
// flist是#指向头节点的指针#的地址，它是一个二级指针
void PushFront(ForwardList *flist, ElementType element) {
  Node *p = NewNode(element);

  p->next_ = *flist;
  *flist = p;
}

// 删除链表头节点
void PopFront(ForwardList *flist) {
  if (!*flist) {
    return;
  }

  ForwardList front = *flist;
  *flist = front ->next_;
  free(front);
}

// 返回指向链表头节点的指针
Iterator Begin(ForwardList *flist) {
  return *flist;
}

// 返回指向链表头节点之前的虚拟节点的指针
// 这个值只是一个标记
Iterator BeforeBegin(ForwardList *flist) {
  return (Iterator)BEFORE_BEGIN;
}

// 返回指向链表尾节点之后的虚拟节点的指针
Iterator End(ForwardList *flist) {
  return NULL;
}

// 在iter所指向节点之后插入一个值为element的节点,返回#指向新插入节点的#迭代器。
// 如果是一个空链表，应该调用BeforeBegin获取迭代器，这个迭代器指向链表头节点的
// 前一个位置，在这个位置之后插入元素才不会发生错误。
//
// 如果有一个空链表，我们传入的迭代器是通过Begin函数获得的，那么iter == NULL，
// 那么显然iter->next_将发生段错误(Segmentation fault (core dumped))，这个错误
// 不由函数来检查，而是由用户自己保证当想要在空链表上InsetAfter时，必须传入由
// BeforeBegin获取的迭代器。这与STL中forward_list模板类的insert_after成员函数
// 的行为是一致的。
Iterator InsertAfter(ForwardList *flist, Iterator iter, ElementType element) {
  Node *p = NewNode(element);

  if (iter == (Iterator)BEFORE_BEGIN) {
    p->next_ = *flist;
    *flist = p;
  } else {
    p->next_ = iter ->next_;
    iter->next_ = p;
  }
  return p;
}

// 删除#iter所指向节点#的后继节点，返回指向#被删除节点的后继节点#的指针。
// 用户需要保证iter迭代器所指的节点有后继节点，不然函数就抛出段错误，这
// 与STL forward_list模板类的erase_after成员函数的行为是一致的。
// BEFORE_BEGIN是一个特殊的迭代器，它指向链表头节点之前的一个虚拟节点。
// 如果iter == BEFORE_BEGIN，那么erase_after的行为等于PopFront。
Iterator EraseAfter(ForwardList *flist, Iterator iter) {
  // iter指向头节点之前的虚拟节点
  if (iter == (Iterator)BEFORE_BEGIN) {
    Node *erased = *flist;
    *flist = erased ->next_;
    free(erased);
    return *flist;
  } else {
    Node *erased = iter->next_;
    iter->next_ = erased -> next_;
    free(erased);
    return iter->next_;
  }
}
