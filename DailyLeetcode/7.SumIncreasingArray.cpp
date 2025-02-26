#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04

/**
 * Input: nums = [10,20,30,5,10,50]
 * Output: 65
 * 
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi= 0;
        for(int i=0;i<nums.size();i++){
            int currSum = nums[i];
            for(int j = i+1; j<nums.size() && nums[j] > nums[j-1]; j++){
                currSum += nums[j];
            }
            maxi = max(maxi,currSum);
        }
        return maxi;
    }
};

//Optimized -- O(n)

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0;
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= nums[i-1]){
                maxi = max(maxi,sum);
                sum = 0;
            }
            sum += nums[i];
        }
        return max(maxi,sum);
    }
};

int main(){

}