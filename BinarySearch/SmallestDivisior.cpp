#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

/**

A: Here the intuition remains same, since we have been given an array we first need to find it's range and then if
   we can eliminate search space then B.S can be applied.

   [1,2,5,9] threshold = 7
   our low will be 1 since divisors can be 1 as well and highest will be array's largest number ==> 9 ==> [1,9]

   1 2 3 4 5 6 7 8 9

   Now if we take divisor as
   1 then ==> 1 + 2 + 5 + 9 = 17 (❌) <= 7
   2 then ==> 1 + 1 + 3 + 5 = 10 (❌) <= 7
   3 then ==> 1 + 1 + 2 + 3 = 7  (✅) <= 7

   Hence here  1 & 2 can be eliminated and we have the remaining search space. Hence we can use B.S here.

*/

class Solution {

private:
int solve(vector<int> &nums, int mid){
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += ceil((double)nums[i]/(double)mid);
    }
    return sum;
}

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solve(nums,mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

int main(){
}