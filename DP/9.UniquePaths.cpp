#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/unique-paths/

// Recursive

class Solution {
private:
    int solve(int i, int j,vector<vector<int>> &dp){
        if(i == 0 and j == 0) return 1;
        if(i < 0 or j < 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = solve(i-1,j,dp) + solve(i,j-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solve(m-1,n-1,dp);
    }
};


//Iterative

int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 and j == 0) dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0 ) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }


//Optimize 

int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i == 0 and j == 0) curr[j] = 1; //we are evaluating current row and hence dp[i] -- > cur
                else{
                    int up = 0, left = 0;
                    if(i > 0 ) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }

            prev = curr;
        }
        return prev[n-1];
    }

int main(){

}