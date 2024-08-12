#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
     void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,int delR[],int delC[],int n,int m)
        {
           vis[row][col] = 1;
           //check for top ,bottom,left,right
           for(int i=0;i<4;i++)
           {
            int nr = row + delR[i];
            int nc = col + delC[i];
            if(nr>=0 and nr <n and nc>=0 and nc<m and !vis[nr][nc] and mat[nr][nc] == 'O')
            {
                //vis[nr][nc] = 1;
                dfs(nr,nc,vis,mat,delR,delC,n,m);
            }
           }
        }
public:
    void solve(vector<vector<char>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
         vector<vector<int>> vis(n,vector<int> (m,0));
        //traversing the first and Last row, so we need to go to every column
        int delR[] ={-1,0,+1,0};
        int delC[] ={0,+1,0,-1};
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] and mat[0][j] == 'O') //if first row is not visited
            {
               dfs(0,j,vis,mat,delR,delC,n,m);
            }
            if(!vis[n-1][j] and mat[n-1][j] =='O') //if last row is not visited
            {
                dfs(n-1,j,vis,mat,delR,delC,n,m);
            }
        }
        //traversing for the first and last column
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] and mat[i][0] == 'O')
            {
                dfs(i,0,vis,mat,delR,delC,n,m);
            }
            if(!vis [i][m-1] and mat[i][m-1]=='O')
            {
                dfs(i,m-1,vis,mat,delR,delC,n,m);
            }
        }
        //if all the boundaries were checked and the current is 'O' not visited, then convert this to 'X'
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                    cout<<mat[i][j]<<endl;
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<mat[i][j]<<endl;
        //     }
        // }
    }
};

int main(){

}