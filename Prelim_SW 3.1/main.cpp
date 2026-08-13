#include <iostream>
#include "singly_ll.h"


int main() {

    //creation of char for "GABO"
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    //allocates memory in the heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;

    head->data = 'G';
    second->data = 'A';
    third->data = 'B';
    fourth->data = 'O';

    //linking the node
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout<<"Testing of Traversal:\n";
    ListTraversal(head);

    std::cout<<"Testing of sllinsertHead:\n";
    sllinsertHead('Q', &head);
    ListTraversal(head);

    std::cout<<"Testing of sllGeneralInsert:\n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);


    std::cout<<"Testing of sllinsertEnd:\n";
    sllinsertEnd('R', &head);
    ListTraversal(head);


    std::cout<<"Testing of sllDeleteNode:\n";
    sllDeleteNode('Q', &head);
    ListTraversal(head);
    sllDeleteNode('X', &head);
    ListTraversal(head);
    sllDeleteNode('R', &head);
    ListTraversal(head);
    
    std::cout<<"Testing of sllDeleteList:\n";
    sllDeleteList(&head);
    ListTraversal(head);


    return 0;


}
