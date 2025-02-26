#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int startRow = entrance[0];
        int startCol = entrance[1];
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        vector<vector<int>> vis(n, vector<int> (m,0));
        queue<pair<int,int>> q;
        q.push({startRow,startCol});
        maze[startRow][startCol] = '+'; //keep in mind this constraint, as entrance cannot be exit
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            steps++; //jab queue se pop karenge tab count karenge
            for(int i=0;i<size;i++){ // we are using for loop here to process all nodes at current step 
                auto row = q.front().first;
                auto col = q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                int nRow = row + dx[d];
                int nCol = col + dy[d];
                if(nRow < n and nRow >= 0 and nCol < m and nCol >=0 and maze[nRow][nCol] == '.' and !vis[nRow][nCol]){
                    //checking if exit and not entrance
                    if(nRow == 0 || nRow == n-1 || nCol== 0 || nCol == m-1){
                        return steps;
                    }
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
        return -1;//no exit found
    }
};

int main(){

}