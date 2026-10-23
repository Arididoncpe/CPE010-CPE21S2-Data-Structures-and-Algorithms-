#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

const int RUNS_L = 1000; // Runs for Linear Search
const int RUNS_B = 1000; // Runs for Binary Search

// O(n) Linear Search
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// O(log n) Binary Search
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void search_test(int n) {
    // 1. Prepare sorted array
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 1); // Fills vector with 1, 2, ..., n

    // 2. Target for Worst Case (element not in array forces maximum comparisons)
    int target = -1;

    volatile int result;

    // Linear Search Benchmark
    auto begin = std::chrono::steady_clock::now();
    for (int r = 0; r < RUNS_L; r++) {
        result = linearSearch(arr, target);
    }
    auto end = std::chrono::steady_clock::now();
    long long time_linear = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / RUNS_L;

    // Binary Search Benchmark
    begin = std::chrono::steady_clock::now();
    for (int r = 0; r < RUNS_B; r++) {
        result = binarySearch(arr, target);
    }
    end = std::chrono::steady_clock::now();
    long long time_binary = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / RUNS_B;

    std::cout << "n = " << n << std::endl;
    std::cout << "Linear Search average time = " << time_linear << " nanoseconds" << std::endl;
    std::cout << "Binary Search average time = " << time_binary << " nanoseconds" << std::endl << std::endl;
}

int main() {
    search_test(1000);
    search_test(10000);
    search_test(100000);

    return 0;
}