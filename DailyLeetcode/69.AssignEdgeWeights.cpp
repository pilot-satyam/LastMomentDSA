//Q : https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/?envType=daily-question&envId=2026-06-12

#include<bitstd/stdc++.h>
using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod = 1e9 + 7;
        int depth = 0;
        int n = edges.size() + 2;
        if(n<=0) return 0;
        if(edges.empty()) return 1;
        //converting to adj list
        vector<vector<int>> adj(n);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(1); 
        vector<int> vis(n,0);
        vis[1] = true;
        int edgePathLength = -1;

        while(!q.empty()){
            int levelSize = q.size();
            edgePathLength++;
            for(int i=0;i<levelSize;i++){
                int curr = q.front();
                q.pop();
                for(int nbr : adj[curr]){
                    if (!vis[nbr]) { 
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
        if (edgePathLength == 0) return 0;
        long long ans = 1;
        for (int i = 0; i < edgePathLength - 1; i++) {
            ans = (ans * 2) % mod;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 4}, {3, 4}};
    cout << sol.assignEdgeWeights(edges1) << endl; // Expected output: 4

    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << sol.assignEdgeWeights(edges2) << endl; // Expected output: 8

    vector<vector<int>> edges3 = {{1, 2}, {1, 3}, {1, 4}, {1, 5}};
    cout << sol.assignEdgeWeights(edges3) << endl; // Expected output: 0
}