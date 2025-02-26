#include<bits/stdc++.h>
using namespace std;

// Q : https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            //checking if left half is sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target and target <= nums[mid]){
                    high = mid-1;
                }
                else low = mid + 1;
            }
            else{
                if(nums[mid]<= target and target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};

int main(){

}