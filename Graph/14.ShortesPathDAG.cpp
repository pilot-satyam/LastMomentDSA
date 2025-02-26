#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &s)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                dfs(v, vis, adj, s);
            }
        }
        s.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        // 1st step is to construct a graph from edges and given matrix
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // finding toposort
        int vis[N] = {0};
        stack<int> s;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, s);
            }
        }

        // 2nd step to find dist array
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while (!s.empty())
        {
            auto node = s.top();
            s.pop();
            if (dist[node] != 1e9)
            {
                for (auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};

int main()
{
}