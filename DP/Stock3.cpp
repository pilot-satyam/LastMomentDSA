#include<bitstdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ 

class Solution {

private:
    int solve(int idx,int buy,int cap, vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
        if(idx == n) return 0;
        if(cap == 0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + solve(idx+1,0,cap,prices,n,dp), 0 + solve(idx+1,1,cap,prices,n,dp));
        }
        else{
            profit = max(prices[idx] + solve(idx+1,1,cap-1,prices,n,dp), solve(idx+1,0,cap,prices,n,dp));
        }
        return dp[idx][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return solve(0,1,2,prices,n,dp);
    }
};

//tabulation :
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            //we can ignore cap = 0 since base case already says that as 0
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    dp[idx][buy][cap] = max(-prices[idx] + dp[idx+1][0][cap], 0 + dp[idx+1][1][cap]);
                }
                else{
                    dp[idx][buy][cap] = max(prices[idx] + dp[idx+1][1][cap-1], dp[idx+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

//space optimized DP :

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> after(2,vector<int> (3,0));
    vector<vector<int>> curr(2,vector<int> (3,0));

    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            //we can ignore cap = 0 since base case already says that as 0
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    curr[buy][cap] = max(-prices[idx] + after[0][cap], 0 + after[1][cap]);
                }
                else{
                    curr[buy][cap] = max(prices[idx] + after[1][cap-1], after[0][cap]);
                }
            }
        }
        after = curr;
    }
    return after[1][2];
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