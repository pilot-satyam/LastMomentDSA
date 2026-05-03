
#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/search-a-2d-matrix/

/*
Dry Run Example:
Matrix:
[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
Target: 3

Matrix has 3 rows (n=3) and 4 columns (m=4), so total elements = 12.
We treat the matrix as a 1D array of length 12:
Index: 0  1  2  3  4  5  6  7  8  9 10 11
Value: 1  3  5  7 10 11 16 20 23 30 34 60

Binary search steps:
low = 0, high = 11
1. mid = (0+11)/2 = 5
    row = 5/4 = 1, col = 5%4 = 1 => matrix[1][1] = 11 > 3, so high = 4
2. mid = (0+4)/2 = 2
    row = 2/4 = 0, col = 2%4 = 2 => matrix[0][2] = 5 > 3, so high = 1
3. mid = (0+1)/2 = 0
    row = 0/4 = 0, col = 0%4 = 0 => matrix[0][0] = 1 < 3, so low = 1
4. mid = (1+1)/2 = 1
    row = 1/4 = 0, col = 1%4 = 1 => matrix[0][1] = 3 == 3, found!
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n*m - 1;
        while(low <= high){
            int mid = low + (high -low)/2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
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
