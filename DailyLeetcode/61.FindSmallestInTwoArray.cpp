//Q : https://leetcode.com/problems/minimum-common-value/?envType=daily-question&envId=2026-05-19 

#include<bits/stdc++.h>
using namespace std;

/**
 * 
 *  Intuition: I was doing earlier the wrong way, I was just using i++,j++; without using else if,
 *  so I was missing the common value when nums1[i] == nums2[j], so I just need to check that first
 *  and return the common value, otherwise I will just move the pointer which is smaller.
 * 
 * T.C ==> O(n1 + n2) 
 * S.C ==> O(1) 
 */


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = -1;
        int i=0,j=0;
        while(i<n1 and j<n2){
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] < nums2[j]) i++;
            else{
                 j++;
            }
        }
        return -1;
    }
};

int main(){

}