#include<bits/stdc++.h>
using namespace std;

// Q : https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=PROBLEM

int longestBitonicSubsequence(vector<int> &nums, int n) {
    
    vector<int> dp1(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[i] > nums[prev])
            dp1[i] = max(dp1[i], 1+dp1[prev]);
        }
    }
    
    vector<int> dp2(n,1);
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(nums[i] > nums[prev])
            dp2[i] = max(dp2[i], 1+dp2[prev]);
        }
    }
    
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, dp1[i] + dp2[i]-1);
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,11,2,10,4,5,2,1};
    int n = nums.size();
    cout<<longestBitonicSubsequence(nums,n);
    return 0;
}