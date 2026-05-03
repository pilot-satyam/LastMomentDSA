#include<bitstd++.h>
using namespace std;

// https://leetcode.com/problems/flip-square-submatrix-vertically/

/**
 * 
 * 
Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3

Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]

        1 2 3 4
        5 6 7 8
        9 10 11 12
        13 14 15 16

        x = 1, y = 0 means 1st row and 0th column is the starting point of rotation and since k = 3 it means we need to select 3 * 3 matrix
 * 
 */

class Solution {
public:
    vector<vector<int>> flipSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int top = x, bottom = x + k - 1; top < bottom; ++top, --bottom) {
            for (int col = y; col < y + k; ++col) {
                swap(grid[top][col], grid[bottom][col]);
            }
        }
        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int x = 1, y = 0, k = 3;

    Solution sol;
    auto result = sol.flipSubmatrix(grid, x, y, k);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << '\n';
    }
    return 0;
}
