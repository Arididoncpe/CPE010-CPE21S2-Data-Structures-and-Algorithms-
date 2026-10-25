#include<iostream>
#include<cstdlib>
#include "sortingAlgo.h"
#include <ctime>

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    // create an array with unsorted list
    int unsortedArr[maxSize];


    //use time (0) as seed
    srand(time(0));

    //populate the array
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }

    //display randomly generated array
    std::cout << "unsortedArr: \n";
    displayArr(unsortedArr);


    /* 
    std::cout << "Bubble Sort: \n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    

    std::cout << "Selection Sort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    
    */
    std::cout << "Insertion Sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

}

void displayArr(int arr[]) {
    for(int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";

    }
        std::cout << std::endl;

}


