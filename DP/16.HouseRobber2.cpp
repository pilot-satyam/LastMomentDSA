#include<bitset/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/house-robber-ii/
// Refer DP/7.MaximumSumNonAdjacent.cpp for explanation of maximum sum of non-adjacent elements

class Solution {

private:
    int solve(vector<int> &nums){
    int prev = nums[0];
    int prev2 = 0;
    int n = nums.size();
    for(int i=1;i<nums.size();i++){
        int pick = nums[i];
        if(i > 1) pick += prev2;
        int nonPick = 0 + prev;
        int curi = max(pick,nonPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //since we have to pick either first one or last one, we make two arrays 
        //One including first house and second excluding first house (or choosing last house)
        vector<int> v1,v2;
        if(n == 1) return nums[0];
        for(int i=0;i<n;i++){
            //v1 excludes the first element (starts from index 1 to n-1).
            if(i != 0) v1.push_back(nums[i]);
            //v2 excludes the last element (starts from index 0 to n-2).
            if(i != n-1) v2.push_back(nums[i]);
        }
        return max(solve(v1), solve(v2));
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,2};
    cout << sol.rob(nums) << endl;
    return 0;
}