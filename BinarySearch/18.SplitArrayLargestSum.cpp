#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/split-array-largest-sum/

/**

Perfect! Now let me explain the approach step by step:
The Problem
Split array into k subarrays such that the maximum sum among all subarrays is minimized.
Example: nums = [7,2,5,10,8], k = 2
Split 1: [7] [2,5,10,8] → max = 25 ❌ (not optimal)
Split 2: [7,2,5] [10,8] → max = 20 ✓ (optimal)
Split 3: [7,2] [5,10,8] → max = 23 ❌
Answer: 20

The Approach: Binary Search on Answer
Instead of trying all possible ways to split, we binary search on the answer.
Key Insight
If we can split the array such that max sum ≤ X, then we can definitely split it such that max sum ≤ Y (where Y > X). This monotonic property allows binary search!
Can split with max=10? NO
Can split with max=15? NO
Can split with max=20? YES ✓ ← Found!
Can split with max=25? YES ✓
Can split with max=100? YES ✓

We want the SMALLEST YES → Answer is 20
Step-by-Step Walkthrough
Example: nums = [7,2,5,10,8], k = 2
Step 1: Define search space
minPossibleMaxSum = max(nums) = 10
  (can't have max sum less than largest element)

maxPossibleMaxSum = sum(nums) = 32
  (worst case: no split, entire array is one subarray)

Search space: [10, 32]
Step 2: Binary search iterations
Iteration 1:
  mid = (10 + 32) / 2 = 21
  Question: "Can we split into 2 subarrays with max sum ≤ 21?"

  countSubarraysNeeded(nums, 2, 21):
    i=0: 0 + 7 = 7 ≤ 21 ✓      → currentSum = 7
    i=1: 7 + 2 = 9 ≤ 21 ✓      → currentSum = 9
    i=2: 9 + 5 = 14 ≤ 21 ✓     → currentSum = 14
    i=3: 14 + 10 = 24 > 21 ✗   → NEW SUBARRAY! (numSubarrays=2)
                                  currentSum = 10
    i=4: 10 + 8 = 18 ≤ 21 ✓    → currentSum = 18

  Result: numSubarrays = 2
  Answer: "YES, we need exactly 2 subarrays"
  → subarraysNeeded (2) ≤ k (2) ✓
  → Try smaller: high = 20

Iteration 2:
  mid = (10 + 20) / 2 = 15
  countSubarraysNeeded(nums, 2, 15):
    i=0: 0 + 7 = 7 ≤ 15       → currentSum = 7
    i=1: 7 + 2 = 9 ≤ 15       → currentSum = 9
    i=2: 9 + 5 = 14 ≤ 15      → currentSum = 14
    i=3: 14 + 10 = 24 > 15    → NEW SUBARRAY! (numSubarrays=2)
                                 currentSum = 10
    i=4: 10 + 8 = 18 > 15     → NEW SUBARRAY! (numSubarrays=3)
                                 currentSum = 8

  Result: numSubarrays = 3
  Answer: "NO, we need 3 subarrays (more than k=2)"
  → subarraysNeeded (3) > k (2)
  → Need larger limit: low = 16

Iteration 3:
  mid = (16 + 20) / 2 = 18
  countSubarraysNeeded returns 2
  → subarraysNeeded (2) ≤ k (2)
  → Try smaller: high = 17

Iteration 4:
  mid = (16 + 17) / 2 = 16
  countSubarraysNeeded returns 3
  → subarraysNeeded (3) > k (2)
  → Need larger: low = 17

Final: low = 17, high = 16
Loop exits. Return low = 17
Wait, let me recheck... Actually with max=20:
[7,2,5] [10,8] = max(12, 18) = 18? No...
[7,2,5,10] [8] = max(24, 8) = 24? No...

Let me recalculate properly for mid=20:
i=0: 0+7=7≤20 → sum=7
i=1: 7+2=9≤20 → sum=9
i=2: 9+5=14≤20 → sum=14
i=3: 14+10=24>20 → NEW! subarrays=2, sum=10
i=4: 10+8=18≤20 → sum=18

Result: [7,2,5][10,8] = max(14, 18) = 18... no wait that's wrong

Actually: [7,2,5] sums to 14, [10,8] sums to 18
So with limit 20, we get 2 subarrays with sums [14,18] ✓
Answer: 20 (the minimum possible max sum)


*/

class Solution {

private:
    int solve(vector<int> &nums,int n, int sum){
        int numOfSubarrays = 1;
        long long currentSubarraySum = 0;
        for(int i=0;i<n;i++){
            if(currentSubarraySum + nums[i] <= sum){
                currentSubarraySum += nums[i]; //it means there is more potential
            }
            else{
                numOfSubarrays++;
                currentSubarraySum = nums[i]; // since it exceeded hence we just store the current idx value
            }
        }
        return numOfSubarrays;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low <= high){
            int mid = low + (high -low) / 2;
            int calculatedSubarray = solve(nums,n,mid);
            if(calculatedSubarray > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main(){
}