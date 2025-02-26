#include<bits/stdc++.h>
using namespace std;

//Q: https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/

//Recursive
class Solution {
private:
   int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m) {
       // Base case: First row, return the matrix value, since it is dynamic idx
       if (i == 0) return matrix[0][j];
       // Out of bounds, return a large value for minimization
       if (j < 0 || j >= m) return INT_MAX;
       // If already computed, return the stored value
       if (dp[i][j] != -1) return dp[i][j];
       int up = matrix[i][j] + f(i - 1, j, matrix, dp, m);
       int left = (j>0) ? matrix[i][j] + f(i - 1, j - 1, matrix, dp, m) : INT_MAX;
       int right = (j<m-1) ? matrix[i][j] + f(i - 1, j + 1, matrix, dp, m) : INT_MAX;
       // Store and return the minimum of all possible paths
       return dp[i][j] = min(up, min(left, right));
   }

   public:
   int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       // DP table initialized with -1
       vector<vector<int>> dp(n, vector<int>(m, -1));
       int mini = 1e8; // Initialize for minimization
       // Try all starting points in the last row
       for (int j = 0; j < m; j++) {
           mini = min(mini, f(n - 1, j, matrix, dp, m));
       }
       return mini;
   }


//iterative

public:
   int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       vector<vector<int>> dp(n, vector<int>(m, -1));
       for(int j=0;j<m;j++) dp[0][j] = matrix[0][j]; //setting dp table 1st row = mat row since no row is above it
       for(int i=1;i<n;i++){ //hence we are starting from 1st row
            for(int j=0;j<m;j++){ //but column remain as it is hence it sstarts from 0
                 int up = matrix[i][j] + dp[i-1][j];
                 int left = (j>0) ? matrix[i][j] + dp[i-1][j-1] : INT_MAX;
                 int right = (j<m-1) ? matrix[i][j] + dp[i-1][j+1] : INT_MAX;
                 dp[i][j] = min(up,min(left,right));
            }
       }
       int mini = INT_MAX;
       for(int j=0;j<m;j++) mini = min(mini,dp[n-1][j]);
       return mini;
   }
};

//Space Optimized:

int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       vector<int> curr(n,0),prev(n,0);
       for(int j=0;j<m;j++) prev[j] = matrix[0][j];
       for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                 int up = matrix[i][j] + prev[j];
                 int left = (j>0) ? matrix[i][j] + prev[j-1] : INT_MAX;
                 int right = (j<m-1) ? matrix[i][j] + prev[j+1] : INT_MAX;
                 curr[j] = min(up,min(left,right));
            }
            prev = curr;
       }
       int mini = INT_MAX;
       for(int j=0;j<m;j++) mini = min(mini,prev[j]);
       return mini; 
   }

int main(){

}