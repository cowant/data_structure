#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef int ElementType;

typedef struct Node {
  ElementType element;
  struct Node *next;
} Node;

typedef Node* ForwardList;
typedef Node* Position;

Position FLFind(ForwardList flist, ElementType element);

ForwardList FLInsert(ForwardList flist, ElementType element);

ForwardList FLErase(ForwardList flist, ElementType element);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FORWARD_LIST_H
