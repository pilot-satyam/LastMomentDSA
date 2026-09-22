// Q : https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/submissions/?envType=daily-question&envId=2026-07-14 

#include<bits/stdc++.h>
using namespace std;

/**
 * Revision notes:
 * - Problem: count subsequence pairs where both selected subsequences have equal GCD.
 * - Key idea: use recursion + memoization over index and current GCDs for two sequences.
 * - State: idx, g1, g2 where g1/g2 are current GCDs for seq1/seq2 (0 means empty).
 * - Choices per element: skip, assign to seq1, assign to seq2.
 * - Base case: reached end, count only if both g1 and g2 are nonzero and equal.
 * - Optimize: dp dimensions use max element value, so max(nums) should be small enough.
 * - Watch out: this counts ordered placement into two groups, not all subsequence pairs with same GCD separately.
 */

class Solution {

const int MOD = 1e9 + 7;

private:
long long solve(int idx, int g1, int g2,vector<int>& nums,vector<vector<vector<int>>> &dp) {

    if (idx == nums.size()) {
        return (g1 != 0 && g2 != 0 && g1 == g2);
    }

    if (dp[idx][g1][g2] != -1)
        return dp[idx][g1][g2];

    int x = nums[idx];

    long long ans = 0;

    // Skip
    ans = (ans + solve(idx + 1, g1, g2, nums, dp)) % MOD;

    // Put in seq1
    int ng1 = (g1 == 0) ? x : gcd(g1, x);
    ans = (ans + solve(idx + 1, ng1, g2, nums, dp)) % MOD;

    // Put in seq2
    int ng2 = (g2 == 0) ? x : gcd(g2, x);
    ans = (ans + solve(idx + 1, g1, ng2, nums, dp)) % MOD;

    return dp[idx][g1][g2] = ans;
}

public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int MAX = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (MAX+1, vector<int> (MAX+1,-1)));
        return solve(0,0,0,nums,dp);
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,4,6};
    cout<<s.subsequencePairCount(nums);
    return 0;
}