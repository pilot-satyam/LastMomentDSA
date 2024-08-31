#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

class Solution {
    
  public:
    bool checkDfs(int node,vector<int> adj[],int vis[],int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            //when node is not visited
            if(!vis[it]){
                if(checkDfs(it,adj,vis,pathVis) == true){
                    return true;
                }
            }
            //already visited, but on diff path
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0}; //it's required that you specify size here, like 'V' here
        int pathVis[V] = {0};
        //for components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkDfs(i,adj,vis,pathVis) == true)
                return true;
            }
        }
        return false;
    }
};

int main(){

}