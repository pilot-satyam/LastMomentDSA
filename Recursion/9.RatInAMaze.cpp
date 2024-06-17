#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    void solve(int i, int j,vector<vector<int>> &m, int n,vector<string> &ans,int di[],int dj[],string move,vector<vector<int>> &vis){
        if(i == n-1 and j == n-1){
            ans.push_back(move);
            return;
        }
        //since lexicographical order
        string dir = "DLRU";
        for(int idx = 0;idx<4;idx++){
            int nexti = i + di[idx];
            int nextj = j + dj[idx];
            if(nexti >= 0 and nextj >= 0 and nexti<n and nextj < n and !vis[nexti][nextj] and m[nexti][nextj] == 1){
                vis[i][j] = 1;
                solve(nexti,nextj,m,n,ans,di,dj,move+dir[idx],vis);
                vis[i][j] = 0;
            }
        }
    }

    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int> (n,0));
        int di[] = {+1,0,0,-1};
        int dj[] = {0,-1,+1,0};
        if(m[0][0] == 1) solve(0,0,m,n,ans,di,dj,"",vis);
        return ans;
    }
};

int main(){

}