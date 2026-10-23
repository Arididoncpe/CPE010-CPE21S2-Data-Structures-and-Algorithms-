#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <thread> 
#include "sortingAlgo.h"

const int maxSize = 10;

void displayArr(int arr[]);

template <typename T>
void parallelQuickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Run left and right partitions in separate threads using header's helper function
        std::thread leftThread(quickSortHelper<T>, arr, low, pivotIndex - 1);
        std::thread rightThread(quickSortHelper<T>, arr, pivotIndex + 1, high);

        leftThread.join();
        rightThread.join();
    }
}

int main() {
    int unsortedArr[maxSize];

    srand(time(0));

    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 10;
    }

    std::cout << "unsortedArr: \n";
    displayArr(unsortedArr);

    std::cout << "\nParallel Quick Sort: \n";

    // Start chrono timer
    auto start = std::chrono::high_resolution_clock::now();

    // Execute parallel quicksort
    parallelQuickSort(unsortedArr, 0, maxSize - 1);

    // Stop chrono timer
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time in microseconds
    std::chrono::duration<double, std::micro> duration = stop - start;

    displayArr(unsortedArr);

    std::cout << "Execution Time: " << duration.count() << " us\n";

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}