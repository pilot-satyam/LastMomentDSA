#include<bits/stdc++.h>
using namespace std;

/*
Approach:
Given an array, find the k-th smallest distance among all pairs (i, j) where i < j.
1. Sort the array.
2. Use binary search on the possible distance (from 0 to max difference).
3. For each mid distance, count how many pairs have distance <= mid using two pointers.
4. If count >= k, search left (smaller distances); else, search right (larger distances).
5. The answer is the smallest distance for which there are at least k pairs.

Dry Run Example:
nums = [1, 3, 1], k = 1
After sorting: [1, 1, 3]
Possible pairs: (1,1)=0, (1,3)=2, (1,3)=2
All distances: [0,2,2], sorted: [0,2,2]
The 1st smallest distance is 0.

Binary search steps:
low=0, high=2
mid=1: countPairs([1,1,3],1) => pairs: (1,1)=0 (ok), (1,3)=2 (not ok), (1,3)=2 (not ok) => count=1
Since count >= k, high=mid-1=0
mid=0: countPairs([1,1,3],0) => only (1,1)=0 (ok) => count=1
Again count >= k, high=mid-1=-1
Loop ends, answer is low=0
*/

class Solution {


private:
    // Intuition:
    // Given a sorted array and a distance 'dist', this function counts how many pairs (i, j) have nums[j] - nums[i] <= dist.
    // It uses two pointers: for each 'right', move 'left' forward until the difference is within 'dist'.
    // The number of valid pairs ending at 'right' is (right - left).
    int countPairs(vector<int> &nums, int dist){
        int cnt = 0;
        int left = 0;
        for(int right=0;right<nums.size();right++){
            while(nums[right] - nums[left] > dist){
                left++;
            }
            cnt += right - left;
        }
        return cnt;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(countPairs(nums,mid) >= k){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,1};
    int k = 1;
    cout << sol.smallestDistancePair(nums, k) << endl;
    return 0;
}