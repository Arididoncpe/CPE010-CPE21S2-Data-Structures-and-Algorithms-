#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo.h"


const int max_size = 50;

int main() {


    /* ===Linear Search Array===
    
    int dataset[max_size];

    srand(time(0));

    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "What number to find: ";
    int choice;

    std::cin >> choice;

    linearSearchAR(max_size, choice, dataset);*/

   /* ===Linear Search Linked List ===
    Node<char> *char1 = newNode('G');
    Node<char> *char2 = newNode('A');
    Node<char> *char3 = newNode('B');
    Node<char> *char4 = newNode('R');
    Node<char> *char5 = newNode('I');
    Node<char> *char6 = newNode('E');
    Node<char> *char7 = newNode('L');


    char1->next = char2;
    char2->next = char3;
    char3->next = char4;
    char4->next = char5;
    char5->next = char6;
    char6->next = char7; 

    
    //linearSearchLL(char1, 'L');
    //linearSearchLL(char1, 'S'); */

   /* ===Binary Search Array ===
    int newArr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < max_size; i++) {
        newArr[i] = i;
    }

    binarysearchArr(newArr, 10, 1); */

// ===== Binary Search Linked List =====

    Node<char> *char1 = newNode('G');
    Node<char> *char2 = newNode('A');
    Node<char> *char3 = newNode('B');

    char1->next = char2;
    char2->next = char3;
    char3->next = nullptr;

    binarySearchLL(char1, 'G');

    return 0;
}