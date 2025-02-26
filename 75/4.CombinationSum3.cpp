#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int idx,vector<vector<int>> &ans,vector<int> &ds,int k,int n){

        if(ds.size() == k and n == 0){
            ans.push_back(ds);
            return;
        }

        if(ds.size() > k or n < 0) return;

        for(int i = idx;i<=9;i++){
            ds.push_back(i);
            solve(i+1,ans,ds,k,n - i); //exploring further hence incrementing i
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,ans,ds,k,n);
        return ans;
    }
};

int main(){

}