#include<bits/stdc++.h>
using namespace std;

int primMST(int n, vector<vector<pair<int, int>>>& adj){
    //since we have an adjacency list, we can use a min-heap (priority queue) to always expand the least weight edge next.
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited (n,false);

    int mstWeight = 0;
    pq.push({0,0}); //{weight, node}
    while(!pq.empty()){
        auto [w, u] = pq. top();
        pq.pop();
        if(visited[u]) continue; //if we have already included this node in MST, skip it
        visited[u] = true; //mark this node as included in MST
        mstWeight += w;
        for(auto& it : adj[u]){
            int edgeWeight = it.first;
            int v = it.second;
            if(!visited[v]){
                pq.push({edgeWeight, v}); //add the edge to the priority queue for consideration
        }
         }
    }
    return mstWeight;
}

int main(){

}