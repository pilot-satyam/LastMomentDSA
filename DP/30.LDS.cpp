#include<bits/stdc++.h>
using namespace std;

//Longest Divisible Subset 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int lastIdx = 0;
        int maxi = 1;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n);
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0 and 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution obj;
    vector<int> ans = obj.largestDivisibleSubset(nums);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}