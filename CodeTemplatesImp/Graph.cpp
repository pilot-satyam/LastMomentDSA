#include<bits/stdc++.h>
using namespace std;

//For the graph templates, assume the nodes are numbered from 0 to n - 1 and the graph is 
// given as an adjacency list. Depending on the problem, you may need to convert the input into 
// an equivalent adjacency list before using the templates.


/*
Graph: DFS (recursive)
*/

unordered_set<int> seen;

int fn(vector<vector<int>>& graph) {
    seen.insert(START_NODE);
    return dfs(START_NODE, graph);
}

int dfs(int node, vector<vector<int>>& graph) {
    int ans = 0;
    // do some logic
    for (int neighbor: graph[node]) {
        if (seen.find(neighbor) == seen.end()) {
            seen.insert(neighbor);
            ans += dfs(neighbor, graph);
        }
    }

    return ans;
}

/*
Graph: DFS (iterative)
*/

int fn(vector<vector<int>>& graph) {
    stack<int> stack;
    unordered_set<int> seen;
    stack.push(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
}

/*
Graph: BFS
*/

int fn(vector<vector<int>>& graph) {
    queue<int> queue;
    unordered_set<int> seen;
    queue.push(START_NODE);
    seen.insert(START_NODE);
    int ans = 0;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        // do some logic
        for (int neighbor: graph[node]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}

//Dijkstra's algo

vector<int> distances(n, INT_MAX);
distances[source] = 0;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
heap.push({0, source});

while (!heap.empty()) {
    int currDist = heap.top().first;
    int node = heap.top().second;
    heap.pop();
    
    if (currDist > distances[node]) {
        continue;
    }
    
    for (pair<int, int> edge: graph[node]) {
        int nei = edge.first;
        int weight = edge.second;
        int dist = currDist + weight;
        
        if (dist < distances[nei]) {
            distances[nei] = dist;
            heap.push({dist, nei});
        }
    }
}

int main(){

}