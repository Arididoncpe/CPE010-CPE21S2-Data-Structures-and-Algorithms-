#include <iostream>
#include <vector>
#include <map>


// Recursive function with memoization
int countPaths(int i, int j, int remaining_cost, const std::vector<std::vector<int>>& mat,
               std::vector<std::vector<std::map<int, int>>>& memo) {
    int M = mat.size();
    int N = mat[0].size();


    // Base Case 1: Out of bounds or cost dropped below zero
    if (i >= M || j >= N || remaining_cost < 0) {
        return 0;
    }


    // Base Case 2: Reached the destination cell
    if (i == M - 1 && j == N - 1) {
        return (remaining_cost == mat[i][j]) ? 1 : 0;
    }


    // Check if this state has already been calculated
    if (memo[i][j].count(remaining_cost)) {
        return memo[i][j][remaining_cost];
    }


    // Move right and move down, deducting current cell's cost
    int next_cost = remaining_cost - mat[i][j];
    int right_paths = countPaths(i, j + 1, next_cost, mat, memo);
    int down_paths = countPaths(i + 1, j, next_cost, mat, memo);


    // Save and return the total paths for this state
    return memo[i][j][remaining_cost] = right_paths + down_paths;
}


int main() {
    // Example 4x4 matrix from the problem statement
    std::vector<std::vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };
   
    int target_cost = 21;
    int M = matrix.size();
    int N = matrix[0].size();


    // 3D Memoization structure: memo[row][col][remaining_cost]
    // Using a map for the 3rd dimension avoids allocating excessive memory for large costs
    std::vector<std::vector<std::map<int, int>>> memo(M, std::vector<std::map<int, int>>(N));


    int total_paths = countPaths(0, 0, target_cost, matrix, memo);


    std::cout << "Number of paths with cost " << target_cost << " is: " << total_paths << std::endl;


    return 0;
}
