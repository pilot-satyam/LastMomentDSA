#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/number-of-enclaves/description/
*/

class Solution {
public:
     int numEnclaves(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int> (m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            //first row,first col, last row, last col
            if(i==0 || j== 0 || i== n-1 || j == m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    while(!q.empty()){
        auto row = q.front().first;
        auto col = q.front().second;
        q.pop();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,+1};
        for(int i=0;i<4;i++){
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            if(nRow >= 0 and nRow<n and nCol >= 0 and nCol < m and !vis[nRow][nCol] and grid[nRow][nCol] == 1){
                vis[nRow][nCol] = 1;
                q.push({nRow,nCol});
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 and !vis[i][j]) cnt++;
        }
    }
    return cnt;
}
};

int main(){

}