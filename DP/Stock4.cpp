#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// The problem is similar to stock3 but here we can have k transactions instead of 2 transactions

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int> (k+1,0));
        vector<vector<int>> curr(2,vector<int> (k+1,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                //we can ignore cap = 0 since base case already says that as 0
                for(int cap=1;cap<=k;cap++){
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
        return after[1][k];
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout<<s.maxProfit(k,prices);
    return 0;
}