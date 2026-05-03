
#include<bits/stdc++.h>
using namespace std;

/*
Intuition:
We want to select k elements from the array such that the difference between the maximum and minimum among those k elements is minimized.

Approach:
1. Sort the array so that elements close in value are adjacent.
2. For every window of size k, the minimum is at the start of the window and the maximum is at the end.
3. The difference for each window is nums[i + k - 1] - nums[i].
    // Explanation: After sorting, for any window of size k starting at index i, the smallest element is nums[i] and the largest is nums[i + k - 1].
    // So, the difference between the maximum and minimum in this window is nums[i + k - 1] - nums[i].
    // Example: If nums = [1, 4, 7, 9] and k = 3, then for i = 0, window is [1, 4, 7], min = 1, max = 7, diff = 7 - 1 = 6.
    // For i = 1, window is [4, 7, 9], min = 4, max = 9, diff = 9 - 4 = 5.
4. Iterate over all possible windows and keep track of the minimum difference found.

Why i + k - 1?
If the window starts at index i, then the k-th element in this window is at index i + k - 1 (since array indices are 0-based). This gives us the last element of the current window of size k.

Dry Run Example:
nums = [9, 4, 1, 7], k = 2
After sorting: [1, 4, 7, 9]
Possible windows of size 2:
    i=0: [1,4] => diff = 4-1 = 3
    i=1: [4,7] => diff = 7-4 = 3
    i=2: [7,9] => diff = 9-7 = 2
Minimum difference is 2.
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i = 0; i + k - 1 < n; i++) {
            // For window starting at i, the last element is at i + k - 1 (window size k)
            // Difference between max and min in this window
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {90};
    int k = 1;
    cout << sol.minimumDifference(nums, k) << endl;
    return 0;
}