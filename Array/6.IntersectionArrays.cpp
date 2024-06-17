#include<bits/stdc++.h>
using namespace std;

LeetCode: https://leetcode.com/problems/intersection-of-two-arrays/editorial/

Ques: Intersection of two sorted arrays

//Where the word sorted is used we can use two pointer approach for Optimization

/*
BRUTE: Take a vis array to mark, if the element is already taken or not while looping the first array
       If the element is already been visited change 0 to 1 of vis array
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = num2.size();
        vector<int> ans;
        int vis[m] = {0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(nums1[i] == nums[j] && vis[j]=0){
                    ans.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }
                if(nums2[j] > nums[i]) break;
            }
        }
        return ans;
    }

/* 
OPTIMIZED
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){

            if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[j] < nums2[i]){
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};


int main()
{

}