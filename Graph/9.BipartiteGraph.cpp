#include <bits/stdc++.h>
using namespace std;

/*
Ques: https://www.geeksforgeeks.org/problems/bipartite-graph/1
*/

/*
Bipartite Graph : A graph which can be colored with 2 colors, w/o adjacent nodes having same color

Linear Graph : This type of graph is always bipartite , since there are no cycles in it and hence no
chance of adjacent node having same color.

**Even Cycle length graph ==> Bipartite

**Odd Cycle length graph ==> Non Bipartite

Here we will take color array instead of vis array and the whole color array will be markes as -1 initially.

*/

// BFS

class Solution
{
public:
private:
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        // q.push(0); // 0 based indexing
        q.push(start);
        // marking intial node color as 0
        color[start] = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                // if adjacency node is not yet colored, then color it with opp color of current node
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                // is the adjacency guy has some color, it means some one did colored it in some other part
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        // initially mark every element as -1
        for (int i = 0; i < V; i++)
            color[i] = -1;
        // iterating over each components of graph
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};

// DFS

class Solution
{

private:
    bool dfs(int node, int col, vector<int> adj[], vector<int> &color)
    {
        color[node] = col;
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !col, adj, color) == false)
                    return false;
            }
            else if (color[it] == col)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        // int color[V];

        // for(int i=0;i<V;i++) color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
}