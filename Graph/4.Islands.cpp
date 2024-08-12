#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://leetcode.com/problems/number-of-islands/description/
*/

class Solution {

    void solve(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            auto row = q.front().first;
            auto col = q.front().second;
            q.pop();
            
            //traversing in neighbours
            int dRow[] = {-1,0,+1,0};
            int dCol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >= 0 and nRow <n and nCol >= 0 and nCol < m 
                   and grid[nRow][nCol] == '1' and !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    cnt++;
                    solve(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};

int main(){

}