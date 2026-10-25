#ifndef MODIFIEDSEARCHING_H
#define MODIFIEDSEARCHING_H

#include <iostream>
#include "node.h"

template<typename T>
int countSequentialAR(int size, T dataFind, T array[]) {
    int count = 0;
    for (int j = 0; j < size; j++) {
        if (dataFind == array[j]) {
            count++;
        }
    }
    return count;
}

template<typename T>
int countSequentialLL(Node<T> *nodes, T dataFind) {
    int count = 0;
    Node<T> *current = nodes;
    while (current != nullptr) {
        if (current->data == dataFind) {
            count++;
        }
        current = current->next;
    }
    return count;
}

template<typename T>
void binSearchArr(T data[], int arrSize, T dataFind) {
    int low = 0, high = arrSize - 1, middle;
    int i= 1;
    while (low <= high) {
        middle = (int)((low + high / 2));
        std::cout << "Iteration " << i << ": low=" << low << " [" << data[low] 
                  << "], high=" << high << " [" << data[high] 
                  << "], middle=" << middle << " [" << data[middle] << "]\n";
        
        if (dataFind == data[middle]) {
            std::cout << "Key " << dataFind << " successfully found at index " << middle << ".\n";
            return;
        } else if (dataFind < data[middle]) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
        i++;
    }
    std::cout << "Key " << dataFind << " was not found.\n";
}

template<typename T>
int binarySearchRecursiveAR(T array[], int low, int high, T dataFind, int depth = 1) {
    // Base Case 1: Target not in list
    if (low > high) {
        std::cout << "Key " << dataFind << " was not found.\n";
        return -1;
    }

    int middle = low + (high - low) / 2;
    std::cout << "Recursion Call " << depth << ": low=" << low 
              << " [" << array[low] << "], high=" << high 
              << " [" << array[high] << "], middle=" << middle 
              << " [" << array[middle] << "]\n";

    // Base Case 2: Target found
    if (dataFind == array[middle]) {
        std::cout << "Key " << dataFind << " successfully found at index " << middle << ".\n";
        return middle;
    } 
    // Recursive Step: Search left half
    else if (dataFind < array[middle]) {
        return binarySearchRecursiveAR(array, low, middle - 1, dataFind, depth + 1);
    } 
    // Recursive Step: Search right half
    else {
        return binarySearchRecursiveAR(array, middle + 1, high, dataFind, depth + 1);
    }
}

#endif