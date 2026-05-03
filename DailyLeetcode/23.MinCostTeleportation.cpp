#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/?envType=daily-question&envId=2026-01-28

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int inf = INT_MAX;
        vector<vector<int>> dp(m , vector<int>(n, inf));
        dp[0][0] = 0;
        for(int i = 0; i<m; i++){
          for(int j = 0; j<n; j++){
            if(i == 0 && j == 0) continue;
            if(i-1>= 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+ grid[i][j]);
            if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+ grid[i][j]);
          }
        }

        for(int t = 1; t<=k; t++){
          const int MAX = 1e4;
          vector<int> best(MAX+1, inf);
          for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
              best[grid[i][j]] = min(best[grid[i][j]], dp[i][j]);

            }
          }
          for(int v = MAX-1; v >= 0; v--){
            best[v]= min(best[v], best[v+1]);
          }
          vector<vector<int>> ndp(m, vector<int>(n, inf));
          ndp[0][0] = 0;
          for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
              if(i == 0 && j == 0) continue;
              ndp[i][j] = best[grid[i][j]];
              if(i-1 >= 0) ndp[i][j] = min(ndp[i][j], ndp[i-1][j] + grid[i][j]);
              if(j-1 >= 0) ndp[i][j] = min(ndp[i][j], ndp[i][j-1] + grid[i][j]);
            }
          }
          dp = ndp;
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{5, 1, 2}, {4, 3, 1}, {1, 2, 0}};
    int k = 1;
    cout << sol.minCost(grid, k) << endl; // Output: 5
    return 0;
}