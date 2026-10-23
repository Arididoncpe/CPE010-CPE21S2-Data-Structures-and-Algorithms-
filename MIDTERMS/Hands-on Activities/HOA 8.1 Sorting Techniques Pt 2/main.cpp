#include<iostream>
#include<cstdlib>
#include "sortingAlgo.h"
#include <ctime>

const int maxSize = 10;

void displayArr(int arr[]);

int main() {
    // create an array with unsorted list
    int unsortedArr[maxSize];


    //use time (0) as seed
    srand(time(0));

    //populate the array
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%10;
    }

    //display randomly generated array
    std::cout << "unsortedArr: \n";
    displayArr(unsortedArr);

 /*
    std::cout << "Shell Sort: \n";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
*/

/*
    std::cout << "Merge Sort: \n";
    mergeSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

*/

    std::cout << "Quick Sort: \n";
    mergeSort(unsortedArr, maxSize);
    displayArr(unsortedArr);


}

void displayArr(int arr[]) {
    for(int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";

    }
        std::cout << std::endl;

}


