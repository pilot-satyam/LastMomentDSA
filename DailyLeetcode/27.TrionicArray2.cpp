#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/trionic-array-ii/?envType=daily-question&envId=2026-02-02

class Solution {
public:
    long long NEG = -100000000000000LL;
    long long UNVISITED = -100000000000001LL;

    vector<vector<long long>> dp;

    long long f(int index, int status, int n, vector<int>& nums) {
        if (index == n) {
            return (status == 3) ? 0LL : NEG;
        }

        if (dp[index][status] != UNVISITED)
            return dp[index][status];

        long long take = NEG;
        long long notTake = NEG;

        if (status == 0) {
            notTake = f(index + 1, 0, n, nums);
        }

        if (status == 3) {
            take = nums[index];
        }

        if (index + 1 < n) {
            if (status == 0 && nums[index + 1] > nums[index]) {
                take = max(take, nums[index] + f(index + 1, 1, n, nums));
            }
            else if (status == 1) {
                if (nums[index + 1] > nums[index]) {
                    take = max(take, nums[index] + f(index + 1, 1, n, nums));
                }
                else if (nums[index + 1] < nums[index]) {
                    take = max(take, nums[index] + f(index + 1, 2, n, nums));
                }
            }
            else if (status == 2) {
                if (nums[index + 1] < nums[index]) {
                    take = max(take, nums[index] + f(index + 1, 2, n, nums));
                }
                else if (nums[index + 1] > nums[index]) {
                    take = max(take, nums[index] + f(index + 1, 3, n, nums));
                }
            }
            else if (status == 3 && nums[index + 1] > nums[index]) {
                take = max(take, nums[index] + f(index + 1, 3, n, nums));
            }
        }

        return dp[index][status] = max(take, notTake);
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<long long>(4, UNVISITED));
        return f(0, 0, n, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.maxSumTrionic(nums) << endl; // Output: 15
    return 0;
}
