#include "gtest/gtest.h"
#include "binary_search_tree.h"


TEST(BSTInsert, BinarySearchTree) {
  SearchTree t = NULL;
  t = BSTInsert(t, 100);
  t = BSTInsert(t, 50);
  t = BSTInsert(t, 201);
  t = BSTInsert(t, 30);
  t = BSTInsert(t, 60);
  t = BSTInsert(t, 101);
  t = BSTInsert(t, 300);

  ASSERT_EQ(t->val, 100);
  ASSERT_EQ(t->left->val, 50);
  ASSERT_EQ(t->right->val, 201);
  ASSERT_EQ(t->left->left->val, 30);
  ASSERT_EQ(t->right->left->val, 101);
  ASSERT_EQ(t->right->right->val, 300);

  ASSERT_TRUE(BSTMakeEmpty(t) == NULL);
}

TEST(BSTFind, BinarySearchTree) {
  SearchTree t = NULL;

  t = BSTInsert(t, 100);
  t = BSTInsert(t, 50);
  t = BSTInsert(t, 201);
  t = BSTInsert(t, 30);
  t = BSTInsert(t, 60);
  t = BSTInsert(t, 101);
  t = BSTInsert(t, 300);

  ASSERT_EQ(BSTFind(t, 100)->val, 100);
  ASSERT_EQ(BSTFindMax(t)->val, 300);
  ASSERT_EQ(BSTFindMin(t)->val, 30);
}

TEST(BSTErase, BinarySearchTree) {
  SearchTree t = NULL;
  ASSERT_TRUE(BSTErase(t, 100) == NULL);

  t = BSTInsert(t, 100);
  t = BSTInsert(t, 50);
  t = BSTInsert(t, 201);
  t = BSTInsert(t, 30);
  t = BSTInsert(t, 60);
  t = BSTInsert(t, 101);
  t = BSTInsert(t, 300);

  t = BSTErase(t, 100);
  ASSERT_EQ(t->val, 101);
  ASSERT_EQ(t->left->val, 50);
  ASSERT_EQ(t->right->val, 201);
  ASSERT_EQ(t->left->left->val, 30);
  ASSERT_EQ(t->left->right->val, 60);
  ASSERT_TRUE(t->right->left == NULL);
  ASSERT_EQ(t->right->right->val, 300);

  ASSERT_TRUE(BSTMakeEmpty(t) == NULL);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
