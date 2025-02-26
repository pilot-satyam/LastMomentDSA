#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/majority-element/description/

// Better soln  
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it : m){
            if(it.second > (n/2)) return it.first;
        }
        return -1;
    }
};

//Moore's Voting Algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0;
        int el;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
            int verify = 0;
            for(int i=0;i<n;i++){
                if(nums[i] == el) verify++;
            }
            if(verify > n/2){
                return el;
            }
        return -1;
    }
};

int main(){

}