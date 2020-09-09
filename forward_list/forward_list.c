#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <assert.h>
#include "forward_list.h"

//  可能返回NULL指针，交给用户处理
static Node* NewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  if (p != NULL) {
    p->val = val;
    p->next = NULL;
  }
  return p;
}


Position FLFind(ForwardList flist, int val) {
  while (flist && flist->val != val) {
      flist = flist->next;
  }
  return flist;
}

// 在头部插入新节点
ForwardList FLInsert(ForwardList flist, int val) {
  Node* node = NewNode(val);
  assert(node != NULL);
  node->next = flist;
  flist = node;

  return flist;
}

// 删除链表中与val相等的首个元素
ForwardList FLErase(ForwardList flist, int val) {
  ForwardList* cur = &flist;
  while (*cur) {
    if ((*cur)->val == val) {
      Node* tmp = *cur;
      *cur = tmp->next;
      free(tmp);
      break;
    } else {
      cur = &(*cur)->next;
    }
  }

  return flist;
}
