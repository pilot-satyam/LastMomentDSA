// Q : https://leetcode.com/problems/coin-change/

#include<bitstd/stdc++.h>
using namespace std;

class Solution {

private:
    int solve(int idx,vector<int> &coins, int target,vector<vector<int>> &dp){
        if(idx == 0){
            if(target % coins[0] == 0) return target / coins[0];
            return 1e9;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int nonPick = 0 + solve(idx-1,coins,target,dp);
        int pick = INT_MAX;
        if(coins[idx] <= target) pick = 1 + solve(idx, coins, target - coins[idx],dp);
        return dp[idx][target] = min(pick, nonPick);
    }

private: 
    int solveTabulation(vector<int> &coins, int target){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (target+1, 0));
        //fill the 0th row
        for(int i=0;i<=target;i++){
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        } 
        for(int idx=1;idx<n;idx++){
            for(int T=0; T<=target;T++){
                int nonPick = 0 + dp[idx-1][T];
                int pick = 1e9;
                if(coins[idx] <= T) pick = 1 + dp[idx][T - coins[idx]];
                dp[idx][T] = min(pick, nonPick);
            }
        }
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;
    }

private:
    int space(vector<int> &coins, int target){
        int n = coins.size();
        vector<int> prev(target+1, 0), curr(target+1, 0);
        //fill the 0th row
        for(int i=0;i<=target;i++){
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        } 
        for(int idx=1;idx<n;idx++){
            for(int T=0; T<=target;T++){
                int nonPick = 0 + prev[T];
                int pick = 1e9;
                if(coins[idx] <= T) pick = 1 + curr[T - coins[idx]];
                curr[T] = min(pick, nonPick);
            }
            prev = curr;
        }
        int ans = prev[target];
        if(ans >= 1e9) return -1;
        return ans;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // int ans = solve(n-1,coins,amount,dp);
        // if(ans >= 1e9) return -1;
        // return ans;
        // return solveTabulation(coins,amount);
        return space(coins,amount);
    }
};

int main(){
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Minimum coins needed for amount " << amount1 << " is: " << sol.coinChange(coins1, amount1) << endl; // Expected output: 3

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Minimum coins needed for amount " << amount2 << " is: " << sol.coinChange(coins2, amount2) << endl; // Expected output: -1

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Minimum coins needed for amount " << amount3 << " is: " << sol.coinChange(coins3, amount3) << endl; // Expected output: 0

     return 0;
}