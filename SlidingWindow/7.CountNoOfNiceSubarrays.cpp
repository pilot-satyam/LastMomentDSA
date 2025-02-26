#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://leetcode.com/problems/count-number-of-nice-subarrays/
*/

class Solution {

public: int solve(vector<int> &nums,int k){
    int l=0,r=0,sum=0,ans=0;
    if (k<0) return 0;
    while(r < nums.size()){
        /*
        For each element nums[r], check if it is odd by taking nums[r] % 2:
        If nums[r] is odd, nums[r] % 2 will be 1, so we add 1 to sum.
        If nums[r] is even, nums[r] % 2 will be 0, so sum remains the same.
        */
        sum+=(nums[r])%2;
        while(sum > k){
            sum-=(nums[l])%2; // since we need to only figure out 0 and 1   
            l++;
        }
        ans += (r-l+1);
        r++;
    }
    return ans;
}

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return solve(nums,k) - solve(nums,k-1); 
    }
};

int main(){

}