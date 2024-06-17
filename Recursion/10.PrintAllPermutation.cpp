#include<bits/stdc++.h>
using namespace std;


class Solution{

    void solve(vector<int> &ds,vector<int> &nums,unordered_map<int,bool> &m,vector<vector<int>> &ans){

        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]) continue; //already marked in map
            else{
                ds.push_back(nums[i]);
                m[nums[i]] = 1;
                solve(ds,nums,m,ans);
                m[nums[i]] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int,bool> m;
        solve(ds,nums,m,ans);
        return ans;
    }
};