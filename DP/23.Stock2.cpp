#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * buy = 1
  |
  +---- BUY  → buy = 0
  |
  +---- SKIP → buy = 1


buy = 0
  |
  +---- SELL → buy = 1
  |
  +---- SKIP → buy = 0
 * 
 */

class Solution {

private:
    int solve(int idx, int buy, vector<int> prices, int n,vector<vector<int>> &dp){
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + solve(idx+1,0,prices,n,dp), 0 + solve(idx+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[idx] + solve(idx+1,1,prices,n,dp), 0 + solve(idx+1,0,prices,n,dp));
        }
        return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int> (2,-1));
        // return solve(0,1,prices,n,dp);
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
            if(buy){
                profit = max(-prices[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
            }
            else{
                profit = max(prices[idx] + dp[idx+1][1], 0 + dp[idx+1][0]);
            }
            dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//Space optimized DP :

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int> (2,-1));
        // return solve(0,1,prices,n,dp);
        // vector<vector<int>> dp(n+1, vector<int> (2,0));
        vector<int> ahead(2,0), curr(2,0);
        ahead[0] = ahead[1] = 0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
            if(buy){
                profit = max(-prices[idx] + ahead[0], 0 + ahead[1]);
            }
            else{
                profit = max(prices[idx] + ahead[1], 0 + ahead[0]);
            }
                curr[buy] = profit;
            }
            ahead = curr;
        }
    return ahead[1];
}

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout<<s.maxProfit(prices);
}