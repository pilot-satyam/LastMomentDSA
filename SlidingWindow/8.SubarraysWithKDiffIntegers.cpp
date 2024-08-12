#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int solve(vector<int> &nums,int k){
        int l=0,r=0,cnt=0;
        unordered_map<int,int> m;
        while(r<nums.size()){
            m[nums[r]]++;
            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]); // checking if the count of nums[l] becomes zero before erasing it. The correct condition should be if (m[nums[l]] == 0) instead of if (m.find(nums[l]) == m.end()), because find checks if the element exist in map or not
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};

int main(){

}