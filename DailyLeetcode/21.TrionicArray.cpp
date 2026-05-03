#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-02

//since we are using while loop it will automatically break when the element will decrease or increase

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        // strictly increasing
        while (i < n && nums[i] > nums[i - 1]) i++;
        if (i == 1 || i == n) return false;

        // strictly decreasing
        while (i < n && nums[i] < nums[i - 1]) i++;
        if (i == n) return false;

        // strictly increasing again
        while (i < n && nums[i] > nums[i - 1]) i++;

        return i == n;
    }
};


int main(){
}