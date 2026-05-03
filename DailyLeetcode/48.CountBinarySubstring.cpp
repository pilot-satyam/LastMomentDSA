#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0;
        int currGroup = 1;
        int count = 0;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                currGroup++;
            } else {
                count += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        count += min(prevGroup, currGroup);

        return count;
    }
};
