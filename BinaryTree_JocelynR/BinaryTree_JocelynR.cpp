// BinaryTree_JocelynR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "BinaryTree.h"

int main()
{
  std::cout << "Hello World!\n";

  BinaryTree<char> demoTree;

  demoTree.insert('8');
  demoTree.insert('5');
  demoTree.insert('9');

  std::cout << "The height of the tree is " << demoTree.height() << endl;
  std::cout << "Inorder is : ";
  demoTree.inOrder();
  std::cout << endl;

  if (demoTree.search('A')) {
    cout << "The value 'A' is found" << endl;
  }
  else {
    cout << "The value 'A' is not found" << endl;
  }

  if (demoTree.search('D')) {
    cout << "The value 'D' is found" << endl;
  }
  else {
    cout << "The value 'D' is not found" << endl;
  }

  //create a binary search tree
  BinaryTree<int> orderedList;

  orderedList.insert(5);
  orderedList.insert(7);
  orderedList.insert(1);
  orderedList.insert(10);
  orderedList.insert(2);
  orderedList.insert(6);
  orderedList.insert(3);
  orderedList.insert(9);
  orderedList.insert(8);
  orderedList.insert(4);

  //use the copy constructor to copy the list
  BinaryTree<int> copiedList(orderedList);
  cout << "Inorder traversal of the copied tree." << endl;
  copiedList.inOrder();
  cout << endl;
  //copiedList.preOrder();
  cout << endl;
  copiedList.postOrder();
  cout << endl;

  //test that it is a deep copy
  copiedList.insert(20);
  cout << "Inorder traversal of the copied tree after insert into copy." << endl;
  copiedList.inOrder();
  cout << endl;
  cout << "Inorder traversal of the original tree after insert into copy." << endl;
  orderedList.inOrder();
  cout << endl;

  //test the search
  cout << "The value 7 does " << (orderedList.search(7) ? " " : "not ") << "exist in the list." << endl;;
  cout << "The value 11 does " << (orderedList.search(11) ? " " : "not ") << "exist in the list." << endl;;
  cout << "The value 20 does " << (orderedList.search(20) ? " " : "not ") << "exist in the list." << endl;;
  cout << "The value 20 does " << (orderedList.search(20) ? " " : "not ") << "exist in the copied list." << endl;;



  //remove with null right SubTree
  orderedList.remove(10);
  //remove a leaf
  orderedList.remove(8);
  //remove with null left SubTree
  orderedList.remove(2);
  //remove with non-null SubTrees
  orderedList.remove(7);
  //remove the root
  orderedList.remove(5);


  cout << "Inorder traversal after removing 10,8,2,7,& 5 of the ordered list." << endl;
  orderedList.inOrder();
  cout << endl;

  cout << "Inorder traversal of the copied tree." << endl;
  copiedList.inOrder();
  cout << endl;


  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
