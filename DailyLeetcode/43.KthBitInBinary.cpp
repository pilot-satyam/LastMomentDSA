#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2026-03-03

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = (len / 2) + 1;

        if (k == mid)
            return '1';

        else if (k < mid)
            return findKthBit(n - 1, k);

        else {
            int mirror = len - k + 1;
            char bit = findKthBit(n - 1, mirror);
            return (bit == '0') ? '1' : '0';  // invert
        }
    }
};