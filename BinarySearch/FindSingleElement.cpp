##include<bits/stdc++.h>
using namespace std;

// Q : https://leetcode.com/problems/single-element-in-a-sorted-array/description/
// A : https://chatgpt.com/c/69615098-f0e8-8324-9431-8af549dc71d1

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid]!=nums[mid+1] and nums[mid]!=nums[mid-1]) return nums[mid];

            if((mid % 2 == 1 and nums[mid]== nums[mid-1]) || (mid%2 == 0 and nums[mid] == nums[mid+1])){
                low = mid + 1;
            }
            //we are on right
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
}