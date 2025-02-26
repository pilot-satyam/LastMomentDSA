#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/assign-cookies/description/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size(), m = s.size();
        int cnt = 0;
        int l = 0, r = 0;
        while(l < n and r < m){
            if(s[r] >= g[l]){
                l += 1;
                cnt++;
            }
            r++; //because in any case we will increase it by 1
        }
        return cnt;
    }
};

int main(){

}