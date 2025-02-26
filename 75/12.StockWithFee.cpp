#include<bits/stdc++.h>
using namespace std;

//Q: https://takeuforward.org/data-structure/buy-and-sell-stocks-with-transaction-fees-dp-40/

class Solution {
public:
    int f(int idx,int buy,vector<int> &prices,int fee,vector<vector<int>> &dp)
    {
        int n = prices.size();
        int profit = 0;
        if(idx == n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy)
        {
            profit = max(-prices[idx]+ f(idx+1,0,prices,fee,dp),0+f(idx+1,1,prices,fee,dp));
        }
        else
        {
            profit = max(prices[idx] - fee + f(idx+1,1,prices,fee,dp),f(idx+1,0,prices,fee,dp));
        }
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return f(0,1,prices,fee,dp);
    }
};


int main(){

}