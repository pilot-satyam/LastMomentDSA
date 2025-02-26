#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //since edges given, we need to create graph
        vector<int> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        q.push(src); // we will only push node in queue, distance we will take from dist array
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};
 
int main(){

}