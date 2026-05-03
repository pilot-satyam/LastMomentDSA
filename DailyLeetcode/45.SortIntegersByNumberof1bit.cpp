#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=daily-question&envId=2026-02-19
class Solution {

private:
    int countOneBits(int x){
        int cnt = 0;
        while(x > 0){
            cnt += (x&1);
            x>>=1;
        }
        return cnt;
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a, int b){
            int cntA = countOneBits(a);
            int cntB = countOneBits(b);
            if(cntA == cntB) return a < b;
            return cntA < cntB; 
        });
        return arr;
    }
};