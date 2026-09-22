//Q : https://leetcode.com/problems/maximum-total-subarray-value-i/?envType=daily-question&envId=2026-06-09

#include<bitstd/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        long long mini = *min_element(nums.begin(),nums.end());
        long long maxi = *max_element(nums.begin(),nums.end());
        ans = k*(maxi - mini);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 2;
    cout << sol.maxTotalValue(nums1, k1) << endl; // Expected output: 6

    vector<int> nums2 = {5, 5, 5};
    int k2 = 3;
    cout << sol.maxTotalValue(nums2, k2) << endl; // Expected output: 0

    vector<int> nums3 = {10, 20, 30};
    int k3 = 1;
    cout << sol.maxTotalValue(nums3, k3) << endl; // Expected output: 20
}