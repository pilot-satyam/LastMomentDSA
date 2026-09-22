#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-path-score-in-a-grid/description/?envType=daily-question&envId=2026-04-30

// class Solution {
// private:
//     int solve(int i, int j, int m, int n, vector<vector<int>> &grid, int k, int cost,
//               vector<vector<vector<int>>> &dp) {

//         if(i >= m or j >= n) return INT_MIN;
//         if(cost > k) return INT_MIN;

//         if(dp[i][j][cost] != -1) return dp[i][j][cost];

//         if(i == m-1 && j == n-1){
//             int newCost = cost + (grid[i][j] != 0);
//             if(newCost > k) return dp[i][j][cost] = INT_MIN;
//             return dp[i][j][cost] = grid[i][j];
//         }

//         int newCost = cost + (grid[i][j] != 0);

//         int right = solve(i, j+1, m, n, grid, k, newCost, dp);
//         int down  = solve(i+1, j, m, n, grid, k, newCost, dp);

//         int best = max(right, down);

//         if(best == INT_MIN)
//             return dp[i][j][cost] = INT_MIN;

//         return dp[i][j][cost] = grid[i][j] + best;
//     }

// public:
//     int maxPathScore(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
//         // int ans = solve(0, 0, m, n, grid, k, 0, dp);
//         // if(ans == INT_MIN) return -1;
//         // return ans;

//         //tabulation --> back filling always
//         for(int i=m-1;i>=0;i--){1
//             for(int j=n-1;j>=0;j--){
//                 for(int cost=k;cost>=0;cost--){
//                     int newCost = cost + (grid[i][j] != 0);
//                     if(newCost > k) continue;
//                     if(i == m-1 && j == n-1) {
//                         dp[i][j][cost] = grid[i][j];
//                         continue;
//                     }
//                     int right = (j+1 < n) ? dp[i][j+1][newCost] : INT_MIN;
//                     int down  = (i+1 < m) ? dp[i+1][j][newCost] : INT_MIN;
//                     int best = max(right, down);
//                     if(best == INT_MIN) continue;
//                     dp[i][j][cost] = grid[i][j] + best;
//                 }
//             }
//         }
//         int ans = dp[0][0][0];
//         return (ans == INT_MIN ? -1 : ans);
//     }
// };

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k+1, INT_MIN))
        );

        // fill from bottom-right
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                for(int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] != 0);
                    if(newCost > k) continue;

                    // base case
                    if(i == m-1 && j == n-1) {
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int right = (j+1 < n) ? dp[i][j+1][newCost] : INT_MIN;
                    int down  = (i+1 < m) ? dp[i+1][j][newCost] : INT_MIN;

                    int best = max(right, down);

                    if(best == INT_MIN) continue;

                    dp[i][j][cost] = grid[i][j] + best;
                }
            }
        }

        int ans = dp[0][0][0];
        return (ans == INT_MIN ? -1 : ans);
    }
};
