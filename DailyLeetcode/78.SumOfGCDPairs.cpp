// Q : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16 

/**
 * Solved completely by myself also this is an optimal solution with O(nlogn) time complexity
 *  and O(n) space complexity.
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> prefixGcd;
        long long ans = 0;
        long long maxi = nums[0];
        for(long long i=0;i<n;i++){
            maxi = max<long long>(maxi,nums[i]);
            long long gcdWithMax = gcd(nums[i],maxi);
            prefixGcd.push_back(gcdWithMax);
        }
        // ans = accumulate(prefixGcd.begin(), prefixGcd.end(),0);
        sort(prefixGcd.begin(),prefixGcd.end());
        long long l = 0, r = n-1;
        while(l < r){
            ans += gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,4,6};
    cout<<s.gcdSum(nums);
}