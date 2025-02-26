#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

/**
 * In one operation, you will:

    Take the two smallest integers x and y in nums.
    Remove x and y from nums.
    Add min(x, y) * 2 + max(x, y) anywhere in the array.

    Input: nums = [2,11,10,1,3], k = 10
    Output: 2

    2 <= nums.length <= 2 * 10^5
    1 <= nums[i] <= 10^9
    1 <= k <= 10^9
 */

/**
 * we are using PQ over here since we want the min element and then we also want to perform remove
 * operation, hence PQ provides efficient way to remove, and using min heap will store the elements
 * in ascending order.
 * 
 * T.C ==> O(nlogn)
 * S.C ==> O(n)
 */

class Solution {
public:
    static int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());// 1 2 3 10 11
        int ans=0;
        while(pq.top()<k){
            long long x=pq.top(); pq.pop(); //1 
            long long y=pq.top(); pq.pop(); //2
            //although the eq is: min(x, y) * 2 + max(x, y) but since we are using x will always be smaller
            pq.push(2*x+y);
            ans++;
        }
        return ans;  
    }
};




int main(){

}