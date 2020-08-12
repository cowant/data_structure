/*
 * 非平衡二叉搜索树
*/

#include "binary_search_tree.h"


static SearchTree NewNode() {
  SearchTree 
SearchTree MakeEmpty(SearchTree T) {
  if (T == NULL) {
    return NULL;
  }

  MakeEmpty(T->left);
  MakeEmpty(T->right);
  free(T);
}
