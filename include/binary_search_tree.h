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

typedef int ElementType;

// 树节点的前向声明
struct TreeNode;
typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Position;

// 初始化
SearchTree MakeEmpty(SearchTree T);

Position Find(SearchTree T);

Position FindMin(SearchTree T);

Position FindMax(SearchTree T);

SearchTree Insert(ElementType X, SearchTree T);

SearchTree Delete(ElementType X, SearchTree T);

ElementType Retrieve(Position P);

struct TreeNode {
  ElementType element;
  SearchTree left;
  SearchTree right;
};

#ifdef __cplusplus
}
#endif

#endif // BINARY_SEARCH_TREE_H
