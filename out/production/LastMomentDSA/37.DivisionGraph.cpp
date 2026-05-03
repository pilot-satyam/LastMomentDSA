#include<bits/stdc++.h>
using namespace std;

/**
 * Intuition:
The problem can be thought of as a graph problem, where each variable (like a, b, c, etc.) is a node, and each equation (like a / b = 2.0) represents a directed edge between two nodes (a and b) with a weight (value of 2.0).

To solve the problem:

Graph Representation: Treat each equation as an edge with a weight, and store this graph in an adjacency list where each node points to its connected nodes along with the division result.
Query Evaluation: For each query, you need to find a path between the two queried nodes in the graph and compute the product of the weights along the path.
The problem boils down to finding the product of weights along the path from the source node to the destination node in the graph. This can be efficiently done using Depth-First Search (DFS) or Breadth-First Search (BFS).

Approach:
Graph Construction:

Use an unordered map of maps (adjacency list) to store the graph.
For each equation a / b = value, add edges a -> b with weight value and b -> a with weight 1 / value.
DFS/BFS for Query Evaluation:

For each query, perform a DFS or BFS to find a path between the two variables.
If the path exists, multiply the weights along the path and return the result.
If no path exists, return -1.0.

*/

bool dfs(string &start, string &end,unordered_map<string,unordered_map<string,double>> &graph,unordered_map<string,bool> &visited,double &result){
    if(start == end){
        return true;
    }
    visited[start] = true;
    for(auto neighbor : graph[start]){
        if(!visited[neighbor.first]){
            result *= neighbor.second;
            if(dfs(neighbor.first,end,graph,visited,result)){
                return true;
            }
            result /= neighbor.second; //backtrack
        }
    }
    return false;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
    //we will be using map under map to create a graph

    /*
    graph = {
    "a": { "b": 2.0 },
    "b": { "a": 0.5, "c": 3.0 },
    "c": { "b": 1/3.0 }
    }
    */

   /**
    * How to Understand this Structure
        This structure is essentially a graph, where:

        Each key in the outer unordered_map is a node (a variable).
        The value for each key is another unordered_map that represents the neighbors of that node and the edge weight (which is the result of the division).
        For example:

        From the node "a", there is an edge to "b" with weight 2.0.
        From the node "b", there are edges to "a" (with weight 0.5) and "c" (with weight 3.0).
        From the node "c", there is an edge to "b" with weight 1/3.0
    * 
    */

   unordered_map<string,unordered_map<string,double>> graph;

   //building the graph
   for(int i=0;i<equations.size();i++){
        string a = equations[i][0], b = equations[i][1];
        double val = values[i];
        graph[a][b] = val; //adding weights to the graph
        graph[b][a] = 1/val; // adding reverse weights to the graph
   }

   vector<double> result;

   //processing queries
   for(auto query : queries){
    string start = query[0], end = query[1];
    if(graph.find(start) == graph.end(end) || graph.find(end) == graph.end()){
        result.push_back(-1.0); //no path found
    }
        else{
            unordered_map<string,bool> visited;
            double res = 1.0;
            if(dfs(start,end,graph,visited,res)){
                result.push_back(res);
            }
            else{
                result.push_back(-1.0); //no path found
            }
        }
   }
   return result;
}

int main(){

}