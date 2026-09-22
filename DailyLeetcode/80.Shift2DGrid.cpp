// Q : https://leetcode.com/problems/shift-2d-grid/?envType=daily-question&envId=2026-07-20 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k%total;
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int old1d = i*n + j;
                int new1d = (old1d + k) % total;
                int new_row = new1d  / n;
                int new_col = new1d % n;
                ans[new_row][new_col] = grid[i][j]; 
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 1;
    vector<vector<int>> ans = s.shiftGrid(grid,k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}