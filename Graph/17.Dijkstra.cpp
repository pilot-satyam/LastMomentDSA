#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Using Priority Queue, we took PQ becuase we wanted 
 * minimum distance to be at first of the Queue, since we are storing pair of {dist,node}
 * 
 * @return int 
 */

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto dis = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int edgeNode = it[0];
                if(edgeWeight + dis < dist[edgeNode]){
                    dist[edgeNode] = dis + edgeWeight;
                    pq.push({dist[edgeNode], edgeNode});
                }
            }
        }
        return dist;
    }
};

/**
 * @brief Using Set : Less T.C
 * 
 * @return int 
 */

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, src});
        dist[src] = 0;
        while (!st.empty())
        {
            auto it = *(st.begin()) // this * points to the value at starting of set
            int dist = it.first;
            int node = it.second;
            st.erase(it);
            for (auto it : adj[node])
            {
                int adjNode = it[0]; // since it is vector<vector<int>> adj[], hence we need to use it[0] or it[1]
                int edgeWeight = it[1];
                if (dist + edgeWeight < dist[adjNode])
                {
                    // erase if the value already existed in dist array, meaning somebody already inserted it
                    st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgeWeight; // updating
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main(){

}