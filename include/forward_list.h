#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef Node* ForwardList;
typedef Node* Position;

Position FLFind(ForwardList flist, int val);

ForwardList FLInsert(ForwardList flist, int val);

ForwardList FLErase(ForwardList flist, int val);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FORWARD_LIST_H
