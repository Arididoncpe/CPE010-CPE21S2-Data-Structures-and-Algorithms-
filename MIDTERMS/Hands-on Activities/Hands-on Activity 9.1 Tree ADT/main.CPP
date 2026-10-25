#include <iostream>
#include "BST.h"
 
int main() {
 
    // =====================================================
    //                   General Tree 
    // =====================================================
    std::cout << "===== GENERAL TREE =====\n";
 
    GeneralTree<char> gTree('A');
    gTree.insert('A', 'B');
    gTree.insert('A', 'C');
    gTree.insert('A', 'D');
    gTree.insert('A', 'E');
    gTree.insert('A', 'F');
    gTree.insert('A', 'G');
    gTree.insert('D', 'H');
    gTree.insert('E', 'I');
    gTree.insert('E', 'J');
    gTree.insert('J', 'P');
    gTree.insert('J', 'Q');
    gTree.insert('F', 'K');
    gTree.insert('F', 'L');
    gTree.insert('F', 'M');
    gTree.insert('G', 'N');
 
    std::cout << "PREORDER: ";
    gTree.preOrder();
    std::cout << std::endl;
 
    std::cout << "INORDER: ";
    gTree.inOrder();
    std::cout << std::endl;
 
    std::cout << "POSTORDER: ";
    gTree.postOrder();
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Find X:" << std::endl;
    gTree.findData("PRE", 'X');
    gTree.findData("IN", 'X');
    gTree.findData("POST", 'X');

    std::cout << "Find J:" << std::endl;
    gTree.findData("PRE", 'J');
    gTree.findData("IN", 'J');
    gTree.findData("POST", 'J');

    std::cout << std::endl;

    std::cout << "Adding O:" << std::endl;
    gTree.insert('G', 'O');
    std::cout << "PREORDER: ";
    gTree.preOrder();
    std::cout << std::endl;
 
    std::cout << "INORDER: ";
    gTree.inOrder();
    std::cout << std::endl;
 
    std::cout << "POSTORDER: ";
    gTree.postOrder();
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Find O:" << std::endl;
    gTree.findData("PRE", 'O');
    gTree.findData("IN", 'O');
    gTree.findData("POST", 'O');



// =====================================================
//                  Binary Search Tree
// =====================================================


/* 

    //create a root node:
    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "PREORDER: \n";
    tree.preOrder();

    std::cout << std::endl;

    std::cout << "INORDER: \n";
    tree.inOrder();

    std::cout << std::endl;

    std::cout << "POSTORDER: \n";
    tree.postOrder();

*/


}