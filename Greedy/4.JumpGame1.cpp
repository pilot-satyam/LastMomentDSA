#include<bits/stdc++.h>
using namespace std;

/**
 * Here we only need to consider the case where we have 0 in arr, so we need to keep in mind,
 * wheter we can jump and cross that 0 or not. so we should be greedy and take the maximum that we can 
 * jump and check if we can reach the end or not.
 * eg. if we have 3 in starting then we can either jump to next element or next->next element
 * or 3rd element, hence we take the 3rd jump as we are greedy and then algo continues.
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //greedy of trying the maximum jump and checking the case where we have 0
        int maxJump = 0;
        for(int i=0;i<nums.size();i++){
            if(i > maxJump) return false;
            maxJump = max(maxJump,i + nums[i]);
            if(maxJump >= nums.size()) return true;
        }
        return true;
    }
};

int main(){

}