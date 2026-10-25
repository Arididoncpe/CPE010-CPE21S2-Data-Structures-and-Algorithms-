#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex outputMutex;

// Function to combine two sorted halves
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];
    }
}

// Sequential Merge Sort
void sequentialMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    sequentialMergeSort(arr, left, mid);
    sequentialMergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

// Parallel Merge Sort using threads and lambda functions
void parallelMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Thread 1: Sort the left half
    std::thread leftThread([&]() {
        sequentialMergeSort(arr, left, mid);

        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "[Thread 1] Left half sorted: ";

        for (int i = left; i <= mid; i++) {
            std::cout << arr[i] << " ";
        }

        std::cout << "\n";
    });

    // Thread 2: Sort the right half
    std::thread rightThread([&]() {
        sequentialMergeSort(arr, mid + 1, right);

        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "[Thread 2] Right half sorted: ";

        for (int i = mid + 1; i <= right; i++) {
            std::cout << arr[i] << " ";
        }

        std::cout << "\n";
    });

    // Wait for both threads to finish
    leftThread.join();
    rightThread.join();

    // Merge the two sorted halves
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> data = {
        38, 27, 43, 3, 9, 82,
        10, 19, 50, 4, 1, 99
    };

    std::cout << "Original Array: ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    // Start parallel sorting
    parallelMergeSort(data, 0, data.size() - 1);

    // Display final sorted array
    std::cout << "\nSorted Array: ";
    for (int x : data) {
        std::cout << x << " ";
    }

    std::cout << "\n\n[SUCCESS] Sorting Complete!\n";

    return 0;
}