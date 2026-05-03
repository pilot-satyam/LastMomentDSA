#include<bits/stdc++.h>
using namespace std;  

//Q: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/?envType=daily-question&envId=2026-01-27

class Solution {
    using PII = pair<int, int>;

public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, 2 * w);
        }

        vector<int> d(n, INT_MAX);
        vector<bool> v(n, false);
        priority_queue<PII, vector<PII>, greater<PII>> q;
        d[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (x == n - 1) {
                return d[x];
            }
            // only the first time unloading requires relaxing other points
            if (v[x]) {
                continue;
            }
            v[x] = 1;

            for (auto& [y, w] : g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    q.emplace(d[y], y);
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 5}, {1, 2, 2}, {1, 3, 1}, {2, 1, 3}, {2, 3, 9}, {2, 4, 2}, {3, 4, 4}};
    cout << sol.minCost(n, edges) << endl; // Output: 8
    return 0;
}