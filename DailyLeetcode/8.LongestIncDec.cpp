#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incCnt = 1, decCnt = 1, ans = 1, n = nums.size()-1;
        for(int i=0;i<n;i++){
            if(nums[i+1] > nums[i]){
                incCnt += 1;
                //since it is decreasing
                decCnt = 1;
            }
            else if(nums[i+1] < nums[i]){
                decCnt += 1;
                incCnt = 1;
            }
            else{
                //since both elements are equal in this case
                incCnt = 1;
                decCnt = 1;
            }
            ans = max(ans,max(incCnt,decCnt));
        }
        return ans;
    }
};

int main(){

}