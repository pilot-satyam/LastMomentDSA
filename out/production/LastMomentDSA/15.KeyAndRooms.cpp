#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(vis[node]) continue;
            if(!vis[node]) vis[node] = 1;
            cnt++;
            for(auto it : rooms[node]){
                q.push(it);
            }
        }
        return cnt == n;
    }
};

int main(){

}