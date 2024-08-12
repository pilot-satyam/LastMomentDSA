#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        } 
        int time = 0;
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        while(!q.empty()){
            auto node = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int t = node.second;
            time = max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >=0 and nRow< n and nCol >= 0 and nCol < m and vis[nRow][nCol] != 2 and grid[nRow][nCol] == 1){
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
                    if(vis[i][j]!=2 and grid[i][j] == 1){
                        return -1;
                    } 
           }
        }
        return time;
    }
};



int main(){

}