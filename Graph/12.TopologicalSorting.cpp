#include <bits/stdc++.h>
using namespace std;

/*
Ques: https://www.geeksforgeeks.org/problems/topological-sort/1
*/

// Using BFS ===> KAHN'S ALGORITHM
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> ans;
        // fetching each node's degree
        int inDegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        // first push the node with degree 0
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }

    /**
     * @brief Note : if toposort size is < (size of V) then it has cycle. Hence it should be equal to (V) size.
     * 
     */

    /**
     * Why We don' require vis array here
     *
     */

    /*
    an element's indegree will become 0 only when all the parent nodes(nodes pointing to it) are
    withdrawn that is put into the topo list. Since every possible node (which could have that element
    as a neighbour) is already taken out of the queue and put into the topo list , so our neighbour
    node won't be touched again.  And for not touching an already touched node , visited array is
    required , and it purpose is already solved in kahn's algorithm itslef ,  so no vis list is required here !!
    */

    // DFS ===> Using Stack

private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &s)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, s);
            }
        }
        // before returning store the node
        s.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, s);
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main()
{
}