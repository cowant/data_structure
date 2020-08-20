#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <assert.h>
#include "forward_list.h"

//  可能返回NULL指针，交给用户处理
static Node* NewNode(ElementType element) {
  Node *p = (Node *)malloc(sizeof(Node));
  if (p != NULL) {
    p->element = element;
    p->next = NULL;
  }
  return p;
}


Position FLFind(ForwardList flist, ElementType element) {
  while (flist) {
    if (flist->element == element) {
      return flist;
    } else {
      flist = flist->next;
    }
  }

  return NULL;
}

// 在头部插入新节点
ForwardList FLInsert(ForwardList flist, ElementType element) {
  Node* node = NewNode(element);
  assert(node != NULL);
  node->next = flist;
  flist = node;

  return flist;
}

// 删除链表中与element相等的首个元素
ForwardList FLErase(ForwardList flist, ElementType element) {
  ForwardList* cur = &flist;
  while (*cur) {
    if ((*cur)->element == element) {
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
