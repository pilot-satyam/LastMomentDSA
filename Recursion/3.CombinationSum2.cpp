#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/combination-sum-ii/description/
// Note: The solution set must not contain duplicate combinations.
class Solution {

public:
    void findCombinationSum(int idx,int target,vector<int>& a,vector<vector<int>> &ans,vector<int>& ds){

        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=idx;i<a.size();i++){
            if(i > idx and a[i]==a[i-1]) continue; // to make sure it does not contain any duplicates
            if(a[i] > target) break;
            ds.push_back(a[i]);
            findCombinationSum(i+1,target-a[i],a,ans,ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(0,target,candidates,ans,ds);
        return ans;
    }
};

int main(){

}