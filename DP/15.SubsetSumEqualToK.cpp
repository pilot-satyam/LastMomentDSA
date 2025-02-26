#include<bits/stdc++.h>
using namespace std;

bool solve(int idx,int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target == 0) return true;
    if(idx == 0) return (arr[0] == target);
    if(dp[idx][target]!= -1) return dp[idx][target];
    bool nonPick = solve(idx-1,target,arr,dp);
    bool pick = false;
    if(arr[idx] <= target) pick = solve(idx-1,target - arr[idx],arr,dp);
    return dp[idx][target] = (pick | nonPick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return solve(n-1,k,arr,dp);
}

int main(){

}