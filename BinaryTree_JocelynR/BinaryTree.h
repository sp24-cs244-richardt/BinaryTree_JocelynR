#pragma once

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

  int height()

};

