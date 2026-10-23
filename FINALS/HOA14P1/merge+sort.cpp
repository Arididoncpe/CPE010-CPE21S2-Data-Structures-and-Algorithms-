#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <thread> 
#include "sortingAlgo.h"

const int maxSize = 10;

void displayArr(const int arr[], int size);

// Parallel Merge Sort 
template <typename T>
void parallelMergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        std::thread leftThread(mergeSortHelper<T>, arr, left, mid);
        std::thread rightThread(mergeSortHelper<T>, arr, mid + 1, right);

        leftThread.join();
        rightThread.join();

        merge(arr, left, mid, right);
    }
}

// Parallel Quick Sort 
template <typename T>
void parallelQuickSort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        std::thread leftThread(quickSortHelper<T>, arr, low, pivotIndex - 1);
        std::thread rightThread(quickSortHelper<T>, arr, pivotIndex + 1, high);

        leftThread.join();
        rightThread.join();
    }
}

int main() {
    int originalArr[maxSize];
    int mergeArr[maxSize];
    int quickArr[maxSize];

    srand(time(0));

    // 1. Populate the initial array and duplicate it
    for (int i = 0; i < maxSize; i++) {
        originalArr[i] = rand() % 100;
        mergeArr[i] = originalArr[i];
        quickArr[i] = originalArr[i];
    }

    std::cout << "Unsorted Array:\n";
    displayArr(originalArr, maxSize);
    std::cout << std::endl;


    // 2. Measure Parallel Merge Sort
    auto startMerge = std::chrono::high_resolution_clock::now();
    parallelMergeSort(mergeArr, 0, maxSize - 1);
    auto stopMerge = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::micro> mergeTime = stopMerge - startMerge;

    std::cout << "Parallel Merge Sort Result:\n";
    displayArr(mergeArr, maxSize);
    std::cout << "Execution Time: " << mergeTime.count() << " us\n\n";


    // 3. Measure Parallel Quick Sort
    auto startQuick = std::chrono::high_resolution_clock::now();
    parallelQuickSort(quickArr, 0, maxSize - 1);
    auto stopQuick = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::micro> quickTime = stopQuick - startQuick;

    std::cout << "Parallel Quick Sort Result:\n";
    displayArr(quickArr, maxSize);
    std::cout << "Execution Time: " << quickTime.count() << " us\n\n";



    return 0;
}

void displayArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}