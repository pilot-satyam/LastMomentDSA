#include<bits/stdc++.h>
using namespace std;

//Q.https://leetcode.com/problems/target-sum/editorial/

//using recursion:
class Solution {
int ans = 0;
private:
    void solve(vector<int> &nums, int idx, int currSum, int target){
        if(idx == nums.size()){
            if(currSum == target){
                ans++;
            }
        }
        else{
            solve(nums,idx+1,currSum + nums[idx],target);
            solve(nums,idx+1,currSum - nums[idx],target);
        }
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,0,0,target);
        return ans;
    }
};

//using dp
class Solution {
int totalSum;
private:
    int solve(vector<int> &nums, int idx, int currSum, int target, vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(currSum == target){
                return 1;
            }
            return 0;
        }
        int shiftedSum = currSum + totalSum;
        if(dp[idx][shiftedSum]!=-1) return dp[idx][shiftedSum];
            int add = solve(nums,idx+1,currSum + nums[idx],target,dp);
            int sub = solve(nums,idx+1,currSum - nums[idx],target,dp);
        return dp[idx][shiftedSum] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = 0;
        for(int i : nums) totalSum += i;
        if(target > totalSum || target < -totalSum) return 0;
        vector<vector<int>> dp(n,vector<int> (2*totalSum + 1,-1));
        return solve(nums,0,0,target,dp);
    }
};

int main(){

}