#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"
#include "modifiedSearching.h"

int main() {
    int dataset[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int target = 18;

    /*
   
   ============Problem 1============
   // ====Sequential Search Array=====
   // linearSearchAR(10, target, dataset);

    // =====Sequential Search Linked List=====
    Node<int> *head = newNode(dataset[0]);
    Node<int> *current = head;
    for (int i = 1; i < 10; i++) {
        current->next = newNode(dataset[i]);
        current = current->next;
    }

    //linearSearchLL(head, target);


    /*

    ============Problem 2============

    int arcount = countSequentialAR(10, target, dataset);
    int llcount = countSequentialLL(head, target);
    std::cout << "Array Count for key '" << target << "': " << arcount << std::endl;
    std::cout << "Linked List Count for key '" << target << "': " << llcount  << std::endl; 
    
    */
    

    //============Problem 3============
    int sortedData[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int target1 = 8;
    binSearchArr(sortedData, 10, target1);
    
    std::cout<<std::endl;

    binarySearchRecursiveAR(sortedData, 0, 9, target1);
    return 0;
}