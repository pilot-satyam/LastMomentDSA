#include<bits/stdc++.h>
using namespace std;

int main()
{

/*
adjacency matrix
*/
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int adj[u][v];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    /*
    Adjaceny list : basically it is an array of datatype either vector, int etc.
    eg: vector<int> adj[n+1]; // it means each index of this has an empty vector
    */

   /* eg. of Adjacency list*/
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vector<int> adj[n+1];
        adj[u].push_back(v);
        adj[v].push_back(u); //for undirected graph --> SC : O(2E)
        //for directed graph --> just comment out 'adj[v].push_back(u);' 
        //since edge already exist, so SC : O(E), as it is consuming only 1 edge 
   }

   /*
    For storing a weighted graph, instead of directly storing the edges, we store
    in pairs like this ===> 4->{2,1}, it means there is a edge b/w 4 & 2 and weight is 1.
   */

  /*
    If given an adjacency matrix and we want to convert it into adjaceny list, then we can do something
    like this.
  */
    int convert(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V+1,0);
        vector<vector<int>> adjLS(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j] == 1 and i!=j) // here this is an optional condition according to given Ques
                {
                adjLS[i].push_back(j);
                adjLS[j].push_back(i);
                }
            }
        }
    }

    /*
    * for iterating in 4 directions
    */

  void iterating4dir(){
     int dRow[] = {-1,0,+1,0};
            int dCol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >= 0 and nRow <n and nCol >= 0 and nCol < m 
                   and grid[nRow][nCol] == '1' and !vis[nRow][nCol]){
                    //condition according to the ques
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                   }
            }
  }

  /*
  * for iterating in 8 directions
  */

    void iterating8dir(){
        
        for(int delrow=-1;delrow<=1;delrow++)
        {
        for(int delcol=-1;delcol<=1;delcol++)
        {
        int nRow = row + delrow;
        int nCol = col + delcol;
        if(nRow >= 0 and nRow <n and nCol >= 0 and nCol < m 
                   and grid[nRow][nCol] == '1' and !vis[nRow][nCol]){
                    //condition according to the ques
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                   }
     }
         }
    }

}