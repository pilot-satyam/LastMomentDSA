#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/ 

class Solution {
private:
    int solve(int idx, int buy, vector<int> &prices,vector<vector<int>> &dp,int n){
        if(idx >= n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy == 1){
            return dp[idx][buy] = max(-prices[idx] + solve(idx+1,0,prices,dp,n), solve(idx+1,1,prices,dp,n));
        }
        return dp[idx][buy] = max(prices[idx] + solve(idx+2,1,prices,dp,n), solve(idx+1,0,prices,dp,n));
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (3,-1));
        return solve(0,1,prices,dp,n);
    }
};

//tabulation :

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (3,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
            if(buy == 1){
                dp[idx][buy] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
            }
            else
                dp[idx][buy] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
            }
        }
    return dp[0][1];
}

// since we know buy == 1 condition will run only when buy is 1 and sell will only run  when buy is 0 so we can can
// remove the inner loop 

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (3,0));
        for(int idx=n-1;idx>=0;idx--){
            dp[idx][1] = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
            dp[idx][0] = max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
        }
    return dp[0][1];
}

//space optimized DP :
 int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> front2(2,0);
    vector<int> front1(2,0);
    vector<int> curr(2,0);

    for(int idx=n-1;idx>=0;idx--){
        curr[1] = max(-prices[idx] + front1[0], front1[1]);
        curr[0] = max(prices[idx] + front2[1], front1[0]);
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}
 

int main(){
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout<<s.maxProfit(prices);
    return 0;
}