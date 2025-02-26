#include<bits/stdc++.h>
using namespace std;

class PathWithMinEffort {
public:
        int minimumEffortPath(vector<vector<int>>& heights) {
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            auto diff = it.first;
            auto row = it.second.first;
            auto col = it.second.second;
            if(row == n-1 and col == m-1) return diff;
            for(int i=0;i<4;i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if(nRow >= 0 and nRow < n and nCol >=0 and nCol < m){
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]),diff);
                    if(newEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                }
            }
        }
        return 0;
    }
};

int main(){

}