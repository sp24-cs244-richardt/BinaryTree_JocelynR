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

public:
  bool search(ELEMENT_TYPE searchElement) {

    //nothing is in the tree
    if (root_ == nullptr) return false;

    //the element is the first in the tree
    BinaryTreeNode* current = root_;

    //while we are at the end of the branch
    while (current != nullptr) {

      if (current->data_ == searchElement) return true;

      //if less move to the left
      else if (searchElement < current->data_) {
        current = current->leftSubTree_;

      //if greater move to the right
      }
      else {
        current = current->rightSubTree_;
      }

    }

    //reached the end of a branch, it's not found
    return false;

  }

  bool insert(ELEMENT_TYPE item) {

    //In-progress - finish debugging next class
    // 
    //wrap item in a node
    BinaryTreeNode* newNode = new BinaryTreeNode(item);

    //create a current to walk through the tree to find location to add element
    BinaryTreeNode* current = root_;
    BinaryTreeNode* trail = nullptr;

    //if our tree is empty
    if (root_ == nullptr) {
      root_ = newNode;
    }

    //while we haven't found an empty spot to place the new node
    while (current != nullptr) {

      //if the item is less than
      if (item < current->data_) {
        trail = current;
        current = current->leftSubTree_;

        //else if the item is greater than
      }
      else if (item > current->data_) {
        trail = current;
        current = current->rightSubTree_;

        //otherwise, they are equal and this tree doesn't allow duplicates
      } else {
        return false;
      }
    }

    //if we made it out of the loop, we can add the element
    if (item < trail->data_) {
      trail->leftSubTree_ = newNode;
    } else {
      trail->rightSubTree_ = newNode;
    }

  }

  bool remove(ELEMENT_TYPE item){
    return false;
  }

};

