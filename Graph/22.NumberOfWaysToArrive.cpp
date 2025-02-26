#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = (long long)(1e9 + 7);
        vector<pair<long long,long long>> adj[n];
        vector<long long> dist(n,1e18), ways(n,0);
        //creating graph
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>> , greater<pair<long long,long long>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            auto distance = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                auto adjNode = it.first;
                auto adjWeight = it.second;
                //this is the first time I am coming with this short distance
                if(distance + adjWeight < dist[adjNode]){
                    dist[adjNode] = distance + adjWeight;
                    pq.push({distance + adjWeight,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(distance + adjWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

int main(){

}