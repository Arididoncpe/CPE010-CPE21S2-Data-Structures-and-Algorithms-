#include <iostream>
#include <vector>
#include <chrono>
 
// returns true if all elements in A are unique
bool Unique(std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j])
                return false;
        }
    }
    return true;
}
 
// Worst case: all elements unique, so every pair is compared -> n(n-1)/2 comparisons
void worst_case_test(int size) {
    std::vector<int> A(size);
    for (int i = 0; i < size; i++)
        A[i] = i + 1;                      
 
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool result = Unique(A);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
 
    std::cout << "Worst case, n = " << size << std::endl;
    std::cout << "Time taken = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;
    std::cout << "Unique returned " << result << std::endl << std::endl;
}
 
// Best case: A[0] == A[1], so Unique stops after 1 comparison
void best_case_test(int size) {
    std::vector<int> A(size);
    for (int i = 0; i < size; i++)
        A[i] = i + 1;
    A[1] = A[0];                          
 
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    bool result = Unique(A);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
 
    std::cout << "Best case, n = " << size << std::endl;
    std::cout << "Time taken = "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
              << " nanoseconds" << std::endl;
    std::cout << "Unique returned " << result << std::endl << std::endl;
}
 
int main() {
    worst_case_test(1000);
    worst_case_test(10000);
    worst_case_test(100000);    
 
    best_case_test(1000);
    best_case_test(10000);
    best_case_test(100000);
    return 0;
}
 