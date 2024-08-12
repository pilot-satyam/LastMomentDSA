#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://leetcode.com/problems/flood-fill/description/
*/

class Solution {

public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int initialColor ,int newColor){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,-1,0,1};
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m 
                and image[nRow][nCol] == initialColor and  ans[nRow][nCol] != newColor){
                    dfs(nRow,nCol,ans,image,initialColor,newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image; //copying the matrix
        dfs(sr,sc,ans,image,initialColor,color);
        return ans;
    }
};

//BFS

class Solution {

public:
    void bfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image, int ini, int newColor){
        ans[row][col] = newColor;
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({row,col});
        while(!q.empty()){
            auto row = q.front().first;
            auto col = q.front().second;
            q.pop();
             for(int i=0;i<4;i++){
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,-1,0,1};
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m 
                and image[nRow][nCol] == ini and  ans[nRow][nCol] != newColor){
                    ans[nRow][nCol] = newColor;
                    q.push({nRow,nCol});
            }
        }
    }
}   
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image; //copying the matrix
        bfs(sr,sc,ans,image,initialColor,color);
        return ans;
    }
};

int main(){

}