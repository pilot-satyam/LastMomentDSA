//Q : https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17

#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    bool canReachEnd(vector<int> &arr, int idx, vector<bool> &vis,int n){
        if(idx < 0 or idx >= n) return false;
        if(vis[idx]) return false;
        if(arr[idx] == 0) return true;
        //marking this node as visited
        vis[idx] = true;
        //trying both directions
        return (canReachEnd(arr,idx-arr[idx],vis,n) or canReachEnd(arr,idx+arr[idx],vis,n));
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);
        return canReachEnd(arr,start,vis,n);
    }
};

int main(){
    Solution sol;
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;
    cout<<sol.canReach(arr,start)<<endl;
}