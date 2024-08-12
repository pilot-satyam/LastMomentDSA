#include<bits.stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto row = q.front().first.first;
            auto col = q.front().first.second;
            auto steps = q.front().second;
            q.pop();
            dis[row][col] = steps;
             int delRow[] = {-1,0,+1,0};
             int delCol[] = {0,-1,0,1};
             for(int i=0;i<4;i++){
                 int nRow = row + delRow[i];
                 int nCol = col + delCol[i];
                 if(nRow>=0 and nRow < n and nCol>=0 and nCol<m and !vis[nRow][nCol]){
                     vis[nRow][nCol] = 1;
                     q.push({{nRow,nCol},steps+1});
                 }
            }
        }
        return dis;
    }
};

int main(){

}