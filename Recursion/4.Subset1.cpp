#include<bits/stdc++.h>
using namespace std;

class Solution {
    
  public: 
    void solve(int idx,int sum,vector<int> &arr, int n, vector<int> &ans){
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        solve(idx+1,sum,arr,n,ans);
        solve(idx+1,sum+arr[idx],arr,n,ans);
    }
    
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
       vector<int> ans;
       solve(0,0,arr,n,ans);
       return ans;
    }
};

int main(){

}