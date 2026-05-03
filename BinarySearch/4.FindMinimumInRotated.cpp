#include<bits/stdc++.h>
using namespace std;

/**
Here the logic is that in most of the cases the minimum element lies in unsorted array :
    eg:    4 5 6 1 2 3   : left sorted : 4 5 6, right unsorted : 6 1 2 3
    But in some cases it might also lie in the other sorted half,
    so we maintain a variable 'ans' we pick the lowest value from sorted half and then eliminate that search space
    then we continue to search in unsorted half and then update the `ans` value.

    General notes :
    1. To determine the sorted half, condition is : nums[low] <= nums [mid]
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]){
              ans = min(ans, nums[low]);
              low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main(){

}