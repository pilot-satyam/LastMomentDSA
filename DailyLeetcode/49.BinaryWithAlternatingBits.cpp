#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        //get last bit
        int prev = n&1;
        //remove last bit
        n>>=1;
        while(n>0){
            //getting current last bit
            int curr = n&1;
            if(curr == prev){
                return false;
            }
            prev = curr;
            //shift right
            n>>=1;
        }
        return true;
    }
};