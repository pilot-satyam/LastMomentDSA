#include<bits/stdc++.h>
using namespace std;

//iterative

int solve(int idx,vector<int> &nums,vector<int> &dp){
    dp[0] = nums[0];
    int n = nums.size();
    if(idx < 0) return 0;
    for(int i=1;i<=nums.size();i++){
        int pick = nums[i] + dp[i-2];
        int nonPick = 0 + dp[i-1];
        dp[i] = max(pick,nonPick);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(n-1,nums,dp);
}

//space optimized
// i-2 ==> prev2, i-1 ==> prev, i ==> curi

int solve(int idx,vector<int> &nums,vector<int> &dp){
    int prev = nums[0];
    int prev2 = 0;
    int n = nums.size();
    for(int i=1;i<nums.size();i++){
        int pick = nums[i];
        if(i > 1) pick += prev2;
        int nonPick = 0 + prev;
        int curi = max(pick,nonPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(n-1,nums,dp);
}

int main(){

}