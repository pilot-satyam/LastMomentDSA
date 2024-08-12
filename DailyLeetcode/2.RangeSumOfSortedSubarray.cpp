#include<bits/stdc++.h>
using namespace std;

/*
Ques :https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-05
*/

class Solution {
    int mod = 1e9 + 7;

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }

        sort(subarraySums.begin(), subarraySums.end());

        int totalSum = 0;
        for(int i = left - 1; i < right; i++) {
            totalSum = (totalSum + subarraySums[i]) % mod;
        }
        return totalSum;
    }
};

//T.C ==> O(n^2log(n))
//Best T.C ===> O(Nlogn) with help of 2 pointer, Please check that solution as well.

int main(){

}