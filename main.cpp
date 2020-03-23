#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    bst.addItem(10);
    bst.addItem(7);
    bst.addItem(20);
    bst.addItem(3);
    bst.addItem(8);
    bst.addItem(15);
    bst.addItem(30);
    bst.addItem(5);
    bst.addItem(9);
    bst.addItem(18);
    bst.addItem(30);
    bst.addItem(2);
    cout << "Added 2." << endl;
    bst.deleteItem(8);
    cout << "Deleted 8." << endl;
    cout << "The inorder successor of 9 is " << bst.inOrderSuccessor(9) << endl;
    cout << "The inorder successor of 3 is " << bst.inOrderSuccessor(3) << endl;
    cout << "Level Order: ";
    bst.levelOrder();
    cout << "Spiral Level Order: ";
    bst.spiralLevelOrder();
    cout << "Left Side View: ";
    bst.leftSideView();
    cout << "Right Side View: ";
    bst.rightSideView();
    cout << "3rd Smallest Item: " << bst.kthSmallestItem(3) << endl;
    return 0;
}
