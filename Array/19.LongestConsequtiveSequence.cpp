#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/longest-consecutive-sequence/
*/


// O(nlogn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); int currCount = 0; int longest = 1; int lastSmaller = INT_MIN;
        if(n == 0) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(nums[i] - 1 == lastSmaller){
                currCount+=1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                currCount = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest,currCount);
        }
        return longest;
    }
};

//O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        if(n == 0) return 0;
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1; 
                int x = it; //first element of sequence
                while(st.find(x+1)!=st.end()){
                    x = x+1;
                    cnt+=1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};




int main(){

}