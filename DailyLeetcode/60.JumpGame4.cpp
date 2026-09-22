//Q : https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18 

#include<bits/stdc++.h>
using namespace std;

// Intuition:
// Treat each index as a graph node.
//
// From index i we can jump to:
// 1. i + 1
// 2. i - 1
// 3. any index j where arr[i] == arr[j]
//
// Since the problem asks for MINIMUM steps/jumps,
// BFS is preferred over DFS because BFS explores
// level by level and guarantees shortest path
// in an unweighted graph.
//
// We use a hashmap:
// value -> all indices having that value
//
// Optimization:
// After processing all indices of a value,
// clear the vector from hashmap to avoid
// revisiting same-value indices repeatedly,
// otherwise complexity can become O(n^2).
//
// Time Complexity  : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        unordered_map<int, vector<int>> m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int idx = q.front();
                q.pop();
                if(idx == n-1) return cnt;

                vector<int> next;

                for(auto it : m[arr[idx]]){
                    next.push_back(it);
                }

                //adjacent jumps
                next.push_back(idx-1);
                next.push_back(idx+1);

                for(auto nbr : next){
                    if(nbr >= 0 and nbr < n and !vis[nbr]){
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
                m[arr[idx]].clear();
            }
            cnt++;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout<<sol.minJumps(arr)<<endl;
}