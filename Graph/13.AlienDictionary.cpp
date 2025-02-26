#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Q: https://www.geeksforgeeks.org/problems/alien-dictionary/1
 * 
 */

class Solution {
    
  private:
      vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> ans;
        // fetching each node's degree
        int inDegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        // first push the node with degree 0
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }

    
  public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        for(int i=0;i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr] != s2[ptr]){
                    //create a node since a appears before b
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                    //and now continue for other nodes
                }
            }
        }
        
        //Now since the graph has been created, do toposorting
        vector<int> res = topoSort(k,adj);
        string ans = "";
        for(auto it : res){
            ans += char(it + 'a');
        }
        return ans;
    }
};

int main(){

}