//Q : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/?envType=daily-question&envId=2026-09-16

#include<bits/stdc++.h>
using namespace std;

class Solution {

const int MOD = 1e9+7;

private:
    long long solve(int idx, int k, int n,vector<vector<long long>> &dp){
        if(k == 0) return 1;
        if(idx == n-1) return 0;
        long long pick = 0, nonPick=0;
        if(dp[idx][k] != -1) return dp[idx][k];
        //nonPick
        nonPick = solve(idx+1,k,n,dp) % MOD;
        //pick
        for(int j=idx+1;j<n;j++){
            pick += solve(j, k-1, n,dp) % MOD;
        }
        return dp[idx][k] = (pick+nonPick) % MOD;
    }

public:
    int numberOfSets(int n, int k) {
        // vector<vector<long long>> dp(n+1,vector<long long> (k+1,-1));
        // return solve(0,k,n,dp) % MOD;
        vector<vector<long long>> dp(n+1,vector<long long> (k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int seg=1;seg<=k;seg++){
            long long suffixSum = 0;
            for(int idx=n-2;idx>=0;idx--){
                //pick 
                suffixSum += (dp[idx+1][seg-1]) % MOD;
                //nonPick + Pick is suffix sum
                dp[idx][seg] = (dp[idx+1][seg]+suffixSum) % MOD;
            }
        }
        return dp[0][k];
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    Solution obj;
    cout<<obj.numberOfSets(n,k)<<endl;
    return 0;
}