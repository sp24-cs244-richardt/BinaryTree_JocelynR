#pragma once

#include <algorithm>

using namespace std;

template <class ELEMENT_TYPE>
class BinaryTree
{

private:
  class BinaryTreeNode {
  public:
    ELEMENT_TYPE data_;
    BinaryTreeNode* leftSubTree_;
    BinaryTreeNode* rightSubTree_;

  public:
    BinaryTreeNode(ELEMENT_TYPE data, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr) :
      data_(data), leftSubTree_(left), rightSubTree_(right) {};
  };

private:
  BinaryTreeNode* root_;

public:
  BinaryTree() {

    root_ = nullptr;

    root_ = new BinaryTreeNode('A');
    root_->rightSubTree_ = new BinaryTreeNode('E');
    root_->leftSubTree_ = new BinaryTreeNode('B');
    root_->leftSubTree_->leftSubTree_ = new BinaryTreeNode('C');
    root_->leftSubTree_->rightSubTree_ = new BinaryTreeNode('D');
  }

  int height() {
    return height(root_);
  }

  void inOrder() {
    inOrder(root_);
  }

  void postOrder() {
    postOrder(root_);
  }

private:
  int height(BinaryTreeNode* root) {

    if (root == nullptr) return 0;

    return 1 + max(height(root->leftSubTree_), height(root->rightSubTree_));
  }

  void inOrder(BinaryTreeNode* node) {

    if (node == nullptr) return;

    inOrder(node->leftSubTree_);
    cout << node->data_;
    inOrder(node->rightSubTree_);

  }

  void postOrder(BinaryTreeNode* node) {

    if (node == nullptr) return;

    inOrder(node->leftSubTree_);
    inOrder(node->rightSubTree_);
    cout << node->data_;

  }
};

