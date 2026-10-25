#include <iostream>
#include <algorithm>
#include <vector>


const int MAXN = 1000;
std::vector<int> memo(MAXN, -1); // Initialize memo array of size 1000 with -1

int getMinSteps(int n) {
    if (n == 1) 
        return 0; // Base case: 1 requires 0 steps
    
    // 1. Look up in cache
    if (memo[n] != -1) 
        return memo[n]; 

    // 2. Compute if not in cache
    int r = 1 + getMinSteps(n - 1);
    if (n % 2 == 0) r = std::min(r, 1 + getMinSteps(n / 2));
    if (n % 3 == 0) r = std::min(r, 1 + getMinSteps(n / 3));

    // 3. Store in cache before returning
    memo[n] = r; 
    return r;
}

int main() {
    int n = 4;
    std::cout << "Min steps for " << n << ": " << getMinSteps(n) << std::endl;
    return 0;
}