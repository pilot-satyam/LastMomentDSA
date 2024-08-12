#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool detect(int src,vector<int> adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            auto node = q.front().first;
            auto parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                /*
                If it has been visited and it is not the parent of the current node, it means 
                there is another path to reach it other than from the parent node. 
                This implies the existence of a cycle because you are revisiting a node that is 
                not your immediate predecessor, meaning there's an alternate route leading back to this node.
                */
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        //We are iterating over each components present in graph and even if one component returns 
        //cycle the whole graph is considered to be cyclic.
        for(int i=0;i<V;i++){ 
            if(!vis[i]){
            if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }

    /*
    T.c ==> O(N+2E) + O(N) , last O(N) is for loop that we are running for components in graph.
    S.c ==> O(N) + O(N)
    */
};

int main(){

}