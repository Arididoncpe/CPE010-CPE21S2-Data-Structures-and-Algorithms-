#include <iostream>
#include <chrono>
 
typedef unsigned long long ull;
 
const int RUNS_R = 1000;        // rpower is slow, so fewer runs
const int RUNS_B = 1000000;     // brpower is very fast, so many runs
 
// O(n): n recursive calls
ull rpower(ull x, int n) {
    if (n == 0) return 1;
    else return x * rpower(x, n - 1);
}
 
// O(log n): n is halved every call
ull brpower(ull x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) {
        ull y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }
    else {
        ull y = brpower(x, n / 2);
        return y * y;
    }
}
 
// times both algorithms for the same n
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
    power_test(2000);
    power_test(4000);
    power_test(8000);
 
    return 0;
}