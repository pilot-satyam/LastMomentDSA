#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2,0), curr(2,0);
        ahead[0] = ahead[1] = 0;
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx]  + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[idx] - fee + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1]; 
    }
};

int main(){
    Solution s;
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout<<s.maxProfit(prices,fee);
    return 0;
}