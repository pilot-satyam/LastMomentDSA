// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=daily-question&envId=2026-05-16

#include<bits/stdc++.h>
using namespace std;

/*
Intuition:

A rotated sorted array always has:
1. one sorted half
2. one half containing the rotation point

The minimum element always lies near the rotation point
(where the sorted order breaks).

If nums[low] <= nums[mid]:
-> left half is sorted
-> nums[low] is the minimum of that half
-> so search in the right (possibly unsorted) half

Else:
-> rotation point lies in left half
-> nums[mid] can be the minimum
-> search left half

Duplicate case:
If nums[low] == nums[mid] == nums[high],
we cannot determine which half is sorted because
duplicates hide the rotation signal.
So we shrink the search space:
low++, high--
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            //duplicate case
            if(nums[low] == nums[mid] and nums[mid] == nums[high]){
                ans = min(ans, nums[low]);
                low++;
                high--;
            }
            //if left half is sorted
            else if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            //else right half is sorted
            else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << sol.findMin(nums) << endl;
    return 0;
}