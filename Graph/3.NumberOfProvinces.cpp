#include<bits/stdc++.h>
using namespace std;

/*
Q: L/C : https://leetcode.com/problems/number-of-provinces/description/
Q: GFG : https://www.geeksforgeeks.org/problems/number-of-provinces/1
*/

class Solution {
    
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adjLS)
    {
        vis[node] = 1;
        for(auto it : adjLS[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adjLS);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V+1,0);
        vector<vector<int>> adjLS(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1 and i!=j)
                {
                adjLS[i].push_back(j);
                adjLS[j].push_back(i);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,vis,adjLS);
            }
        }
        return cnt;
    }
};