/*
 * 非平衡二叉搜索树
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 树节点的前向声明
struct TreeNode;
typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Position;

// 初始化
SearchTree BSTMakeEmpty(SearchTree t);

Position BSTFindMin(SearchTree t);
Position BSTFindMax(SearchTree t);
Position BSTFind(SearchTree t, int val);

SearchTree BSTInsert(SearchTree t, int val);
SearchTree BSTErase(SearchTree t, int val);

typedef struct TreeNode {
  int val;
  SearchTree left;
  SearchTree right;
} TreeNode;

#ifdef __cplusplus
}
#endif

#endif // BINARY_SEARCH_TREE_H
