#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16 
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        for(int i=1;i<arrays.size();i++){
            maxi = max(maxi,abs(arrays[i].back() - minVal));
            maxi = max(maxi,abs(maxVal-arrays[i][0]));
            minVal = min(minVal,arrays[i][0]);
            maxVal = max(maxVal,arrays[i].back());
        }
        return maxi;
    }
};

int main(){

}