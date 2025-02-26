#include<bits/stdc++.h>
using namespace std;

/**
 * Ques: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
 * 
 */

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=1;i<=n;i++) parent[i] = i; //initially mark with their respective indexes
        dist[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top(); //here we are traversing in pq, {dist,node}
            auto dis = it.first;
            auto node = it.second;
            pq.pop();
            for(auto it : adj[node]){  
                auto adjNode = it.first; // here we are traversing in adj List, hence {node,wt}
                auto wt = it.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt,adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1}; //if the node is unreachable
        vector<int> path;
        //starting from n and not from 0, since you had to store in where you are coming from
        int node = n;
        //O(n) ==> In worst case it could take linear path, eg. 1->2->3->4......etc
        //so total T.C ==> O(Elog(V)) + O(n)
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); //pushing 1 since it is src and hence no parent
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};

int main(){

}