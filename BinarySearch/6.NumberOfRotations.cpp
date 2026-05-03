##include<bits/stdc++.h>
using namespace std;


/**
Number of rotations in a rotated sorted array = index of the minimum element
Why this works (intuition)

In a rotated sorted array, one half is always sorted

If left half is sorted → minimum could be at low

Else → minimum could be at mid

We compare and keep updating the smallest element with its index
*/

int findKRotation(vector<int> &nums){
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Left part sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] < ans) {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right part sorted
        else {
            if (nums[mid] < ans) {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main(){
}