#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-convert-string-i/?envType=daily-question&envId=2026-01-28

class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        const int V = 26;

        // Build graph
        vector<vector<int>> adj[V];
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        long long ans = 0;

        // Cache distances
        vector<vector<long long>> allDist(V);

        for (int c = 0; c < V; c++) {
            allDist[c] = dijkstra(V, adj, c);
        }

        // Compute answer
        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (u == v) continue;
            if (allDist[u][v] == 1e18) return -1;

            ans += allDist[u][v];
        }

        return ans;
    }

    vector<long long> dijkstra(
        int V,
        vector<vector<int>> adj[],
        int src
    ) {
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;

        vector<long long> dist(V, 1e18);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto dis = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int edgeNode = it[0];
                int edgeWeight = it[1];
                if (dis + edgeWeight < dist[edgeNode]) {
                    dist[edgeNode] = dis + edgeWeight;
                    pq.push({dist[edgeNode], edgeNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;
    string source = "abc";
    string target = "bcd";
    vector<char> original = {'a', 'b', 'c'};
    vector<char> changed = {'b', 'c', 'd'};
    vector<int> cost = {1, 1, 1};
    cout << sol.minimumCost(source, target, original, changed, cost) << endl; // Output: 3
    return 0;
}
