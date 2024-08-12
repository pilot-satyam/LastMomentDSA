#include<bits/stdc++.h>
using namespace std;
/*
Revision
*/

vector<int> bfsExample(int V, vector<int> adj[]){
    //since 0 based indexing graph
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]){ //====> this for loop responsible for O(2E), since we need to visit each degree of a node
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
  return bfs;
}

/*

T.C ==> O(N) + O(2E)
S.c ==> O(3N)

*/

/*
    DFS : Always executes with help of recursion
*/

void dfs(int start, vector<int> adj[], int vis[], vector<int> &ans){
    vis[start] = 1;
    ans.push_back(start);
    for(auto it : adj[start]){
        if(!vis[it]){
            vis[it] = 1;
            dfs(start,adj,vis,ans);
        }
    }
}

vector<int> dfsExample(int V, vector<int> adj[]){
    vector<int> ans;
    int vis[V] = {0}; 
    int start = 0;
    dfs(start,adj,vis,ans);
    return ans;
}


int main(){

}