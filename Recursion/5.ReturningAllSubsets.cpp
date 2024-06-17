#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    void solve(int idx,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans)
    {   
        ans.push_back(ds);
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(0,nums,ds,ans);
        return ans;
    }
};

int main(){

}