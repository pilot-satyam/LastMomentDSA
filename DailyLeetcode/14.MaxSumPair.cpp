#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

//Brute Force: 
// T.C ==> O(n) , S.C ==> O(n)

/**
 * [18,43,36,13,7] ==> sum = 9, m[9] = 18,
 *                     sum = 7, m[7] = 43,
 *                     sum = 9, ans = max(-1, m[9] + 36) == (-1,18+36) (-1,54)==> m[9] = max(m[9],36) == (18,36) = 36
 *                     sum = 4, m[4] = 13
 *                     sum = 7, ans = max(54,m[7] + 7) == (54,50) ==> m[7] = max(m[7],7) == max(43,7) = 43
 */


class Solution {

private:
    int calculateSum(int n){
        int sum = 0;
        while(n > 0){
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = -1;
        for(auto it : nums){
            int sum = calculateSum(it);
            if(m.find(sum) != m.end()){
                ans = max(ans, m[sum] + it);
                m[sum] = max(m[sum],it);
            }
            else{
                m[sum] = it;
            }
        }
        return ans;
    }
};

/**
 * Sol: 
1️⃣ Sum of Digits Calculation:

For each number, calculate its sum of digits using division and modulo operations.
2️⃣ Track Maximum Values:

Use an array of size 82 to store the largest number for each possible digit sum.
If a second number with the same digit sum is found, calculate their sum and update the maximum result if needed.
3️⃣ Efficient Updates:

Keep the maximum number for each sum of digits to avoid redundant calculations.
    9+9+9+9+9+9+9+9+9 = 81 (given constraint 10^9)
 * 
    T.C ==> O()
    S.C ==> O()
 */

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxi[82] = {0};
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            int sum = 0, temp = nums[i];
            while(temp!=0){
                sum += temp%10;
                temp /= 10;
            }
            if(maxi[sum]!=0) ans = max(ans, nums[i] + maxi[sum]);
            maxi[sum] = max(maxi[sum],nums[i]);
        }
        return ans;
    }
};

int main(){

}