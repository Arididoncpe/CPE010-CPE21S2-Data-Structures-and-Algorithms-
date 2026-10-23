#include "node.h"


#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H


template<typename T>
void linearSearchAR(int size, T dataFind, T array[]) {

    for (int j = 0; j < size; j++) {
        if(dataFind == array[j]) {
            std::cout << "Searching is successful\n";
            return;
        }

    }
    std::cout << "Searching is unsuccessful\n";
}


template<typename T>
int linearSearchCount(int size, T dataFind, T array[]) {
    int count = 0;
    for (int j = 0; j < size; j++) {
        if(dataFind == array[j]) {
            count++;
        }

    }
    return count;
}


template<typename T>
void linearSearchLL(Node<T> *nodes, T dataFind) {

while(nodes != nullptr){

    if(nodes->data == dataFind){
        std::cout << "The data: " << nodes->data << " was found successfully.\n";
        return;
        }
    nodes = nodes->next;

    }
    std::cout << "Searching is unsuccessful.\n";
}   

template<typename T> 
void binarysearchArr(T data[], int arrSize, T dataFind){
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = (int)((low + high / 2));
        if(dataFind == data[middle]){
            std::cout << "Data was found.\n";
            return;
        }
        else if(dataFind < data[middle]){
            high = middle - 1;

        }
        else{
            low = middle + 1;
        }
    }
    std::cout << "Data was not found\n";


}

template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;
    
    //continue until fast reaches the end or the last node of the current search range
    while(fast != last && fast->next != last) {

        //move slow one step
        slow = slow->next;
        //move fast two steps
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    //set start to the head of the list and set last to null
    Node<T>* last = nullptr;

    while(start != last){
        
        Node<T> *middle = getMiddle(start, last);

        // If the middle element is same as the key to be searched, we return it.
        if(middle->data == dataFind){
            std::cout << "Searching is successful\n";
            return;
        }
        // Else if middle element is greater than the key to be searched,
        // we have to search in the left side of the singly linked list.
        else if(middle->data > dataFind){
            last = middle;
        }
        // Else if middle element is less than the key to be searched,
        // we have to search in the right side of the singly linked list.
        else{
            start = middle->next;
        }
    }

    std::cout << "Searching is unsuccessful\n";
}



#endif