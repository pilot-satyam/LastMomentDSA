#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/?envType=study-plan-v2&envId=leetcode-75

//very similar to this : https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,maxLen=0,zeroes = 0;
        while(r < nums.size()){
            if(nums[r] == 0) zeroes++;
            if(zeroes > 1){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <= 1) {
                int len = r-l;
                maxLen = max(maxLen,len);
            }
            r++;
        }
        return maxLen;

    }
};

int main(){
