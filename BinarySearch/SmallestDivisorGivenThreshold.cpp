#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/ 

class Solution{

private:
    int solveSum(vector<int> &nums, int mid){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double) nums[i] / (double) mid);
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums,int threshold){
        int low = 1, high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solveSum(nums, mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

};

int main(){

}