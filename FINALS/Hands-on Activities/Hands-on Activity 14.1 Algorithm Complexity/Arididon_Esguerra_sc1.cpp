#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <numeric>
#include "sortingAlgo.h"

// Parallel Merge Sort Wrapper
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

// Parallel Quick Sort Wrapper
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

// Benchmark Helper using Multi-threading
void run_test(const std::string& label, std::vector<int> arr, bool isQuick) {
    auto begin = std::chrono::steady_clock::now();

    if (isQuick) {
        parallelQuickSort(arr.data(), 0, arr.size() - 1);
    } else {
        parallelMergeSort(arr.data(), 0, arr.size() - 1);
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    std::cout << label << " | n = " << arr.size() << " | Time: " << elapsed << " microseconds\n";
}

int main() {
    for (int n : {100, 1000, 10000}) {
        std::vector<int> sorted(n), reverse(n);

        std::iota(sorted.begin(), sorted.end(), 1);      // 1, 2, ..., n
        for (int i = 0; i < n; i++) reverse[i] = n - i;  // n, n-1, ..., 1

        std::cout << "===== Testing n = " << n << " =====\n";

        // Parallel Merge Sort Tests
        run_test("[Parallel Merge Sort] Best ", sorted, false);
        run_test("[Parallel Merge Sort] Worst", reverse, false);

        // Parallel Quick Sort Tests
        run_test("[Parallel Quick Sort] Best ", reverse, true);
        run_test("[Parallel Quick Sort] Worst", sorted, true);

        std::cout << "-------------------------------------------\n\n";
    }

    return 0;
}