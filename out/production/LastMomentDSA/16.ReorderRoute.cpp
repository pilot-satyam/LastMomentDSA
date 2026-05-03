#include<bits/stdc++.h>
using namespace std;

//Q:https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75

/*
Intuition : reverse all the node links and then check wheter it is reachable to 0thnode or not

//constrcuted graph
Graph Representation (node -> {neighbor, needsReorder}):

0 -> {1, true}, {4, false}      (0 -> 1 needs reorder)
1 -> {0, false}, {3, true}      (1 -> 3 needs reorder)
2 -> {3, true}                  (2 -> 3 needs reorder)
3 -> {1, false}, {2, false}     (no reorder needed for 1 -> 3 and 2 -> 3)
4 -> {0, true}, {5, true}       (4 -> 0 and 4 -> 5 need reorders)
5 -> {4, false}                 (no reorder needed for 5 -> 4)

*/

class Solution {

private:
    void dfs(int node,vector<vector<pair<int, bool>>> &graph,vector<bool> &vis,int &reorderCount){
        vis[node] = true;
        for(auto [neighbor,needsReorder] : graph[node]){
            if(!vis[neighbor]){
                if(needsReorder) reorderCount++;
                dfs(neighbor,graph,vis,reorderCount);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Step 1: Create the graph representation
    vector<vector<pair<int, bool>>> graph(n); 

    for (const auto& conn : connections) {
        int u = conn[0], v = conn[1];
        // Add directed edges to the graph (u -> v and v -> u), with boolean indicating whether reorder is needed
        graph[u].push_back({v, true});  // true indicates that we need to reorder the path u -> v
        graph[v].push_back({u, false}); // false indicates no reorder is needed for v -> u
    }

    // Step 2: Perform DFS from city 0 and count reorders
    vector<bool> vis(n, false);  // To track which nodes have been visited
    int reorderCount = 0;

    dfs(0, graph, vis, reorderCount);  // Start DFS from city 0

    return reorderCount;

    }
};

int main(){

}