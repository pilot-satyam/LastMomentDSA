// Q : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/?envType=daily-question&envId=2026-07-04

#include<bitstd/stdc++.h>
using namespace std;

/**
 * 
 * Here the only catch is that we have to find the minimum score of a path between two cities. 
 * The score of a path between two cities is defined as the minimum distance of a road in this path. 
 * We can use BFS or DFS to traverse the graph and find the minimum score. But I have used BFS here since problem says 
 * minimum score of a path between two cities. So we can use BFS to find the minimum.
 * 
 * Don't get confused with the phrasing that path can be traced back.
 */

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<bool> vis(n+1,false);
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto e : roads){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        queue<int> q;
        q.push(1);
        // vis[1] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto [next, weight] : graph[node]){
                ans = min(ans, weight);
                if(!vis[next]){
                    q.push(next);
                    vis[next] = true;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    cout<<s.minScore(n, roads)<<endl;
    return 0;
}