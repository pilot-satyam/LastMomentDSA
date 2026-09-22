#include<bits/stdc++.h>
using namespace std;

/***
 * 
 * We use prev_idx + 1 as a coordinate shift to prevent negative array index errors when storing values in the memoization 
 * table (dp).Here is exactly how it works:1. The Meaning of prev_idx = -1When you start computing the Longest Increasing 
 * Subsequence (LIS), the very first element has no previous element to compare itself against. 
 * 
 * To represent this "empty" or
 * "none" state, the code initializes prev_idx to -1 (solve(0, -1, nums, dp)).2. The Indexing ProblemArray indices in C++
 * must start at 0. If you try to access dp[idx][prev_idx], it will translate to dp[idx][-1] on the first run. 
 * This triggers an out-of-bounds error or segmentation fault because negative indices do not exist.3. 
 * 
 * 
 * The Coordinate Shift SolutionTo safely store -1 in the dp table, the code shifts the index by +1:When prev_idx == -1, 
 * it maps to dp[idx][-1 + 1] \(\rightarrow \) dp[idx][0]When prev_idx == 0, it maps to dp[idx][0 + 1] \(\rightarrow \) 
 * dp[idx][1]When prev_idx == n-1, it maps to dp[idx][(n-1) + 1] \(\rightarrow \) dp[idx][n]4. 
 * Matching the DP Table DimensionsBecause of this shift, the column size of your dp table needs to expand.
 * Instead of needing indices from 0 to n-1 (size n), you now need indices from 0 to n (size n + 1).
 * 
 * 
 */


//Memoization

class Solution {

private:
    int solve(int idx, int prev_idx, vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        if(idx == n) return 0;
        if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
        int len = 0;
        //non-pick 
        len = max(len, 0+solve(idx+1, prev_idx,nums,dp));
        //pick
        if(prev_idx == -1 or nums[idx] > nums[prev_idx]){
            len = max(len, 1+solve(idx+1,idx,nums,dp));
        }
        return dp[idx][prev_idx+1] = len;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return solve(0,-1,nums,dp);
    }
};

//Tabulation 

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i] > nums[prev])
                dp[i] = max(dp[i], 1+dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }
    return maxi;
}

// Printing

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lastIdx = 0;
        int maxi = 1;
        vector<int> dp(n,1), hash(n);
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] > nums[prev] and 1+dp[prev] > dp[i])
                {
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        reverse(temp.begin(), temp.end());
        for(auto it : temp) cout << it << " ";
        cout<<endl;
        return maxi;
    }
};


//Binary Search

//T.c ==> O(nlogn) and S.c => O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmp;
        tmp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] > tmp.back()){
                tmp.push_back(nums[i]);
            }
            else{
                //do a binary search
                int idx = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                //go to tmp idx and say this where we will replace
                tmp[idx] = nums[i];
            }
        }
        return tmp.size();
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(nums);
    return 0;
}