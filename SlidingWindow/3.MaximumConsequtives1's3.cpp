#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxLen=0,zeroes = 0;
        while(r < nums.size()){
            if(nums[r] == 0) zeroes++; //if encounter any 0 then increment the counter
            if(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <= k) {
                int len = r-l+1;
                maxLen = max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};

int main(){

}