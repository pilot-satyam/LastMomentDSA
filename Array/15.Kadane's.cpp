#include<bits/stdc++.h>
using namespace std;

long long  maxSubarraySum(vector<int> &a, int n){
    long long sum = 0;
    long long maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum > maxi){
            maxi = sum;
        }

        if(sum < 0){
            sum = 0; //reinitializing to 0 since we don't consider negative sum
        }
    }
    return maxi;
}

//FOLLOW UP QUES: PRINTING THE SUBARRAY WITH MAX SUM, ANY SUBARRAY AS THERE CAN EXIST MANY SUBARRAYS

#include <iostream>
#include <vector>

vector<int> findMaxSubarray(vector<int>& nums) {
     long long sum = 0;
    long long maxi = LONG_MIN;
    int start = 0;
    int temp_start = 0;
    std::vector<int> max_subarray;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > maxi) {
            maxi = sum;
            start = temp_start;
            end = i;
        }

        if (sum < 0) {
            sum = 0; // reinitializing to 0 since we don't consider negative sum
            temp_start = i + 1; // since sum = 0 to hum next index se lenge na for max sum
        }
    }

    // Constructing the maximum subarray
    for (int i = start; i < n; i++) {
        max_subarray.push_back(a[i]);
        if (sum == maxi) break; // Stop when the sum reaches the maximum sum
    }

    return {maxi, max_subarray};
}


int main() {
    std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    auto result = maxSubarraySum(nums, nums.size());
    long long max_sum = result.first;
    std::vector<int> max_subarray = result.second;

    std::cout << "Max Subarray with Maximum Sum: ";
    for (int num : max_subarray) {
        std::cout << num << " ";
    }
    std::cout << "\nMaximum Sum: " << max_sum << std::endl;

    return 0;
}

DRY-RUN: 
nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }.

Initially:

max_sum = INT_MIN, current_sum = 0, start = 0, end = 0, temp_start = 0.
i = 0: Element -2

current_sum += nums[0] => current_sum = -2.
current_sum is less than 0, so we reset current_sum to 0 and update temp_start to 1.
i = 1: Element 1

current_sum += nums[1] => current_sum = 1.
current_sum is greater than max_sum, so we update max_sum = 1, start = temp_start = 1, end = 1.
i = 2: Element -3

current_sum += nums[2] => current_sum = -2.
current_sum is less than 0, so we reset current_sum to 0 and update temp_start to 3.
i = 3: Element 4

current_sum += nums[3] => current_sum = 4.
current_sum is greater than max_sum, so we update max_sum = 4, start = temp_start = 3, end = 3.
i = 4: Element -1

current_sum += nums[4] => current_sum = 3.
current_sum is still positive.
i = 5: Element 2

current_sum += nums[5] => current_sum = 5.
current_sum is greater than max_sum, so we update max_sum = 5, start = temp_start = 3, end = 5.
i = 6: Element 1

current_sum += nums[6] => current_sum = 6.
current_sum is greater than max_sum, so we update max_sum = 6, start = temp_start = 3, end = 6.
i = 7: Element -5

current_sum += nums[7] => current_sum = 1.
current_sum is positive.
i = 8: Element 4

current_sum += nums[8] => current_sum = 5.
current_sum is greater than max_sum, so we update max_sum = 6, start = temp_start = 3, end = 8.
After the loop:

max_sum = 6, start = 3, end = 8.
The maximum subarray is from index 3 to 8, which is { 4, -1, 2, 1 }. This subarray has the maximum sum of 6.

 
