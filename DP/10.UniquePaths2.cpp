#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
   int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
       if (i < 0 || j < 0) return 0;  // Out of bounds
       if (grid[i][j] == 1) return 0;  // Cell is blocked
       if (i == 0 && j == 0) return 1; // Reached the starting cell
       if (dp[i][j] != -1) return dp[i][j];  // Use memoized value
       dp[i][j] = (solve(i - 1, j, dp, grid) + solve(i, j - 1, dp, grid));
       return dp[i][j];
   }
public:
   int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
// If the start or end cell is blocked, return 0
       if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;
       vector<vector<int>> dp(n, vector<int>(m, -1));
       return solve(n - 1, m - 1, dp, grid);
   }
};

int main(){

}