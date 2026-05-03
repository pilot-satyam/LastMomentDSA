#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/search-a-2d-matrix-ii/

/*
Approach:
Given a matrix where each row and each column is sorted in ascending order, we can efficiently search for a target by starting from the top-right corner:
- If the current element equals the target, return true.
- If the current element is less than the target, move down to the next row (row++).
- If the current element is greater than the target, move left to the previous column (col--).
This works because moving down increases values and moving left decreases values.

Dry Run Example:
Matrix:
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 60]
]
Target: 16

Start at (row=0, col=3) => matrix[0][3]=7 < 16, so row++
Now (row=1, col=3) => matrix[1][3]=20 > 16, so col--
Now (row=1, col=2) => matrix[1][2]=16 == 16, found!

Another example, Target: 13
Start at (0,3): 7 < 13, row++
(1,3): 20 > 13, col--
(1,2): 16 > 13, col--
(1,1): 11 < 13, row++
(2,1): 30 > 13, col--
(2,0): 23 > 13, col--
col < 0, not found, return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m-1;
        while(row < n and col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 3;
    cout << sol.searchMatrix(matrix, target) << endl;
    return 0;
}