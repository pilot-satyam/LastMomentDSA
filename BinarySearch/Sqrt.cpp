##include<bits/stdc++.h>
using namespace std;

/**
Q : https://leetcode.com/problems/sqrtx/description/
A : Intuition is that whenever you have to find a result where you can eliminate a certain search space then use binary search
    Like here suppose n = 25 and after ans = 5 you can element all the elements since they will be greater than 25 and then
    you can use the BS logic to trim down the ranges further.
*/

class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        int low = 1, high = x;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;
            if(val <= x){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};

int main(){
}