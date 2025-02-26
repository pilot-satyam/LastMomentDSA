#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/min-cost-climbing-stairs/post-solution/?submissionId=1477318934


class Solution {
    int solve(int idx,vector<int>& cost,vector<int> &dp,int n){
        if(idx == 0) return cost[0];
        if(idx == 1) return cost[1];
        if(dp[idx]!=-1) return dp[idx];
        int pick = cost[idx] + solve(idx-2,cost,dp,n);
        int nonPick = cost[idx] + solve(idx-1,cost,dp,n);
        return dp[idx] = min(pick,nonPick);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        //he can either start from last or second last
        return min(solve(n-1,cost,dp,n),solve(n-2,cost,dp,n));
    }
};

//optimized 

class Solution {
    int solve(int idx,vector<int>& cost,vector<int> &dp,int n){
        if(n == 1) return cost[0];
        int prev2 = cost[0];
        int prev = cost[1];
        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev,prev2);
            prev2 = prev;
            prev = curr;
        }
        return min(prev,prev2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        //he can either start from last or second last
        return min(solve(n-1,cost,dp,n),solve(n-2,cost,dp,n));
    }
};

int main(){

}