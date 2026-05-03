#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=daily-question&envId=2026-03-03

// /**
// pattern could be : 0101 (OR) 1010

// */

// class Solution {
// public:
//     int minOperations(string s) {
//         int pattern1 = 0;
//         int pattern2 = 0;
//         int n = s.size();
//         for(int i=0;i<n;i++){
//             //1st pattern
//             char expected1 = (i%2 == 0) ? '0': '1';
//             //2nd pattern
//             char expected2 = (i%2 == 0) ? '1' : '0';
//             if(s[i] != expected1) pattern1++;
//             if(s[i] != expected2) pattern2++;
//         }
//         return min(pattern1 , pattern2);
//     }
// };

class Solution {
public:
    int minOperations(string s) {

        int mismatch = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {

            if(s[i] != (i % 2 ? '1' : '0'))
                mismatch++;
        }

        return min(mismatch, n - mismatch);
    }
};