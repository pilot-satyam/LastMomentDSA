#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://www.geeksforgeeks.org/problems/eventual-safe-states/0
*/

class Solution {
    
  private:
    bool dfs(int node,int vis[],int path[],vector<int> adj[], int check[]){
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0; //initially not safe node
        for(auto it : adj[node]){
            if(!vis[it]){
               if(dfs(it,vis,path,adj,check) == true){
                   check[node] = {0};
                   return true;
               }
            }
            //since path has already been visited, means there is a cycle
            else if(path[it] == true) {
                check[node] = 0;
                return true; 
            }
        }
        //after all iterations, if no cycle found and path has not been visited earlier
        check[node] = {1};
        path[node] = {0};
        return false; //no cycle
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
       vector<int> ans;
       int vis[V] = {0};
       int path[V] = {0};
       int check[V] = {0};
       for(int i = 0;i<V;i++){
           if(!vis[i]){
               dfs(i,vis,path,adj,check);
           }
        //    if(check[i] == 1){
        //        ans.push_back(i);   ====> Can also be done like this
        //    }
       }
      for(int i = 0;i<V;i++){
          if(check[i] == 1){
              ans.push_back(i);
          }
      }
       return ans;
    }
};

/**
 * @brief Using Kahn's algorithm --- BFS
 * 
 */

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){

}