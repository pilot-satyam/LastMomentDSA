#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/?envType=daily-question&envId=2026-02-19

class Solution {

private:
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i == 0) return false;
        }
        return true;
    }

private:
    int countBits(int n){
        int cnt = 0;
        while(n > 0){
            cnt += n&1;
            n >>= 1;
        }
        return cnt;
    }

public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++){
            int bits = countBits(i);
            if(isPrime(bits)) ans++;
        }
        return ans;
    }
};