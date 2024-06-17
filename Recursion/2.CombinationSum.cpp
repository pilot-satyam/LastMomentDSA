#include<bits/stdc++.h>
using namespace std;

class Solution {

public: void solve(int idx,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){

    if(idx == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }

    if(arr[idx] <= target){
        ds.push_back(arr[idx]);
        //we can pick same index
        solve(idx,target - arr[idx],arr,ans,ds);
        ds.pop_back();
    }
    // we can't pick same idx since > 0
    solve(idx+1,target,arr,ans,ds);
}

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,candidates,ans,ds);
        return ans;
    }
};

int main(){
    
}