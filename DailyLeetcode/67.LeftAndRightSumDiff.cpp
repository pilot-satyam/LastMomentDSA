//Q : https://leetcode.com/problems/left-and-right-sum-differences/description/?envType=daily-question&envId=2026-06-06

#include<bitstd/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> leftRightDifference(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> leftSum(n);
//         vector<int> rightSum(n);
//         vector<int> ans(n);

//         int left = 0;
//         int right = 0;
        
//         leftSum[0] = 0;
//         rightSum[n-1] = 0;

//         for(int i=1;i<n;i++){
//             leftSum[i] = leftSum[i-1] + nums[i-1];
//         }
//         for(int i=n-2;i>=0;i--){
//             rightSum[i] = nums[i+1] + rightSum[i+1]; 
//         }
//         for(int i=0;i<n;i++){
//             ans[i] = abs(leftSum[i]-rightSum[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {10, 4, 8, 3};
    vector<int> result1 = sol.leftRightDifference(nums1);
    for (int val : result1) {
        cout << val << " "; // Expected output: [15, 1, 11, 22]
    }
    cout << endl;

    vector<int> nums2 = {1};
    vector<int> result2 = sol.leftRightDifference(nums2);
    for (int val : result2) {
        cout << val << " "; // Expected output: [0]
    }
    cout << endl;

    return 0;
}