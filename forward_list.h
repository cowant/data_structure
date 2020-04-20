#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <stddef.h>

typedef enum Bool {
  TRUE = 1,
  FALSE = 0
} Bool;

typedef int ElementType;

typedef struct Node {
  ElementType element_;
  struct Node *next_;
} Node;

typedef Node *ForwardList;
typedef Node *Position;

// 构建单向链表
ForwardList Construct(size_t nums, ...);

// 释放单向链表
void Destruct(ForwardList *flist);

// 判断链表是否为空
Bool Empty(ForwardList *flist);

// 访问链表的第一个元素
ElementType Front(ForwardList *flist);

// 在链表头部插入一个新元素
void PushFront(ForwardList *flist, ElementType element);

// 删除链表头部的元素
void PopFront(ForwardList *flist);

// 将新值插入指定位置后面
void InsertAfter(ForwardList *flist, Position *pos, ElementType element);

#endif // FORWARD_LIST_H
