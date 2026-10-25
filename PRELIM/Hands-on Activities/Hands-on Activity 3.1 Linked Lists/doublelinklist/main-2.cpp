#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){
    DoubleList<char>* head = CreateNewNode('G');
    DoubleList<char>* second = CreateNewNode('A');
    DoubleList<char>* third = CreateNewNode('B');
    
    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;


    //traversal
    std::cout <<"Testing DLL Traversal: "<< std::endl;
    dllTraverse(head);

    //headinsert
    std::cout <<"Testing insert head: " << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //testing insert at end
    std::cout <<"Testing insert at the end: "<< std::endl;
    dllInsertEnd('Z', head);
    dllTraverse(head);

    //testing general insert
    std::cout <<"Testing of General Insert: " << std::endl;
    std::cout <<"Insert at 4th node: " << std::endl;
    dllGeneralInsert('6', head->next->next);
    dllTraverse(head);
    
    std::cout <<"Insert at 5th node: " << std::endl;
    dllGeneralInsert('7', head->next->next->next);
    dllTraverse(head);


    //testing delete node
    std::cout <<"Testing of Deleting Node: " << std::endl;
    dllDeleteNode('X',&head);
    dllTraverse(head);
    dllDeleteNode('Z',&head);
    dllTraverse(head);
    dllDeleteNode('6',&head);
    dllTraverse(head);
    dllDeleteNode('7',&head);
    dllTraverse(head);

}

