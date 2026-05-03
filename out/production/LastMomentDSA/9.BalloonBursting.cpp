#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int cnt = 1;
        sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        });
        int prevHigh = points[0][1];
        for(int i = 1;i<points.size();i++){
            //if the current balloon starts after the end of prev balloon
            //it means we need new arrow to burst this balloon
            if(points[i][0] > prevHigh){
                cnt++;
                prevHigh = points[i][1];
            }
        }
        return cnt;
    }
};

int main(){

}