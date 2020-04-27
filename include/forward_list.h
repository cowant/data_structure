#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#define BEFORE_BEGIN 0x01

typedef enum {
  TRUE = 1,
  FALSE = 0
} Bool;

typedef int ElementType;

typedef struct Node {
  ElementType element_;
  struct Node *next_;
} Node;

typedef Node *ForwardList;
typedef Node *Iterator;

Node* NewNode(ElementType element);

ForwardList Construct(size_t nums, ...);

void Destruct(ForwardList *flist);

Bool Empty(ForwardList flist);

Iterator Begin(ForwardList *flist);

Iterator BeforeBegin(ForwardList *flist);

Iterator End(ForwardList *flist);

ElementType Front(ForwardList flist);

void PushFront(ForwardList *flist, ElementType element);

void PopFront(ForwardList *flist);

Iterator InsertAfter(ForwardList *flist, Iterator iter, ElementType element);

Iterator EraseAfter(ForwardList *flist, Iterator iter);

void Remove(ForwardList *flist, ElementType element);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FORWARD_LIST_H
