#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++){
            int res = -1;
            int index = m[nums1[i]];
            for(int j = index+1;j<nums2.size();j++){
                if(nums2[j] > nums1[i]){
                    res = nums2[j];
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};

int main(){

}