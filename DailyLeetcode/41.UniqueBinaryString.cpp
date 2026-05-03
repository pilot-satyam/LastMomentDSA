#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-03

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if(nums[i][i] == '0'){
                ans += '1';
            }
            else ans += '0';
        }
        return ans;
    }
};