/*
 * 非平衡二叉搜索树
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "binary_search_tree.h"


// 构造一个树节点，可能返回一个空指针，由用户负责判断
static TreeNode* NewNode(int val) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  if (node != NULL) {
    node->val = val;
    node->left = NULL;
    node->right = NULL;
  }

  return node;
}

SearchTree BSTMakeEmpty(SearchTree t) {
  if (t == NULL) {
    return NULL;
  }

  t->left = BSTMakeEmpty(t->left);
  t->right = BSTMakeEmpty(t->right);
  free(t);
}

Position BSTFind(SearchTree t, int val) {
  while (t != NULL) {
    if (t->val > val) {
      t = t->left;
    } else if (t->val < val) {
      t = t->right;
    } else {
      return t;
    }
  }

  return NULL;
}

Position BSTFindMin(SearchTree t) {
  while (t != NULL && t->left != NULL) {
    t = t->left;
  }
  return t;
}

Position BSTFindMax(SearchTree t) {
  while (t != NULL && t->right != NULL) {
    t = t->right;
  }
  return t;
}

SearchTree BSTInsert(SearchTree t, int val) {
  if (t == NULL) {
    t = NewNode(val);
    assert(t != NULL);
  } else {
    if (val > t->val) {
      t->right = BSTInsert(t->right, val);
    } else if (val < t->val) {
      t->left = BSTInsert(t->left, val);
    }
  }

  return t;
}

// val: 被删除的节点的值
// t: 指向树的根节点
// 返回删除某个节点后的新树
SearchTree BSTErase(SearchTree t, int val) {
  // 边界条件检查，递归退出条件
  if (t == NULL) {
    return NULL;
  }

  // val位于右子树，递归删除右子树中的节点val
  if (val > t->val) {
    t->right = BSTErase(t->right, val);
  // val位于右子树，递归删除右子树中的节点val
  } else if (val < t->val) {
    t->left = BSTErase(t->left, val);
  // 找到节点val，执行删除操作
  } else {
    // 节点val有两个儿子
    if (t->left != NULL && t->right != NULL) {
      // 找到右子树的最小节点
      TreeNode* tmp = BSTFindMin(t->right);
      // 保留这个最小节点的值
      t->val = tmp->val;
      // 删除这个最小节点
      t->right = BSTErase(t->right, tmp->val);
    // 节点val有一个或者没有儿子
    } else {
      TreeNode* tmp = t;
      // 没有左儿子
      if (t->left == NULL) {
        t = t->right;
      // 没有右儿子
      } else if (t->right == NULL) {
        t = t->left;
      }
      free(tmp);
    }
  }

  return t;
}
