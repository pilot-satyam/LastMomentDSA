#include<bits/stdc++.h>
using namespace std;

//Q:https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2026-01-24

//minimization happens via how we choose the pairs
//pair smallest with largest, this pairing strategy is what guarantees the minimum possible maximum.


//Let’s say after sorting:

// a ≤ b ≤ c ≤ d

//  Bad pairing
// (a, b) and (c, d)
// max = c + d   ❌ huge

// Greedy pairing
// (a, d) and (b, c)
// max = max(a+d, b+c)


// Now observe:

// c + d ≥ a + d


// So any pairing that puts d with someone other than a
// will make the maximum worse or equal.

// Therefore: The safest place for the largest element is with the smallest one.


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0, right = n-1, ans = 0;
        while(left < right){
            ans = max(ans, nums[left] + nums[right]);
            left++;
            right--;
        }
        return ans;
    }
};

// Proof for Interview:
/**
 * 
 * https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/editorial
 * 
 */

int main(){

}