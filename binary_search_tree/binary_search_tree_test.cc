#include "gtest/gtest.h"
#include "binary_search_tree.h"


TEST(MakeEmpty, BinarySearchTree) {
  SearchTree t = (SearchTree)malloc(sizeof(struct TreeNode));
  t->
  MakeEmpty(t);
}


int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
