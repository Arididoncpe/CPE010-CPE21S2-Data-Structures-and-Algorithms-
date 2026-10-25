#include <iostream>
#include <chrono>
 
typedef unsigned long long ull;
 
const int RUNS_R = 1000;        
const int RUNS_B = 1000;     // Lowered to prevent terminal freeze
 
// O(n) Iterative Loop
ull rpower(ull x, int n) {
    ull result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}
 
// O(log n) Iterative Loop
ull brpower(ull x, int n) {
    ull result = 1;
    ull base = x;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= base;
        }
        base *= base;
        n /= 2;
    }
    return result;
}
 
void power_test(int n) {
    volatile ull result;                    
 
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (int r = 0; r < RUNS_R; r++)
        result = rpower(2, n);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long long time_r = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / RUNS_R;
 
    begin = std::chrono::steady_clock::now();
    for (int r = 0; r < RUNS_B; r++)
        result = brpower(2, n);
    end = std::chrono::steady_clock::now();
    long long time_b = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() / RUNS_B;
 
    std::cout << "n = " << n << std::endl;
    std::cout << "rpower  average time taken = " << time_r << " nanoseconds" << std::endl;
    std::cout << "brpower average time taken = " << time_b << " nanoseconds" << std::endl << std::endl;
}
 
int main() {
    power_test(1000);
    power_test(10000);
    power_test(100000);
 
    return 0;
}
