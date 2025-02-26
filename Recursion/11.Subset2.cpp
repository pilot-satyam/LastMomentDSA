#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds) {
        //no base case since it will check the termination logic in for loop
        ans.push_back(ds);
        for (int i = idx; i < nums.size();i++) {
            if (i > idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i + 1, nums, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end()); // added so that all the duplicates are coupled together
        solve(0, nums, ans, ds);
        return ans;
    }
};


int main(){

}