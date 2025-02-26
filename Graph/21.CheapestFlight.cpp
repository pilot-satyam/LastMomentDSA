#include<bits/stdc++.h>
using namespace std;

class CheapestFlight {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        
        dist[src] = 0;
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});//stops,node,dist
        while(!q.empty()){
            auto stops = q.front().first;
            auto node = q.front().second.first;
            auto distance = q.front().second.second; 
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[node]){
                auto adjNode = it.first;
                auto edgeWeight = it.second;
                if(distance + edgeWeight < dist[adjNode] && stops <= k){
                    dist[adjNode] = distance + edgeWeight;
                    q.push({stops+1,{adjNode, distance + edgeWeight}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main(){
    
}