# Intuition:
# The problem asks for the largest distance between two consecutive 1's in the binary representation of a number. We need to find the maximum gap between positions of 1's as we traverse the bits from right to left.
#
# Approach:
# - Traverse each bit of the number from least significant to most significant.
# - Track the position of the previous 1 encountered.
# - For each new 1, calculate the gap from the previous 1 and update the maximum gap found.
# - Continue until all bits are processed.

#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-gap/description/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int curr = 0;
        int maxi = 0;
        while(n > 0){
            if(n&1){
                //it means it has some index
                if(prev != -1){
                    maxi = max(maxi, curr - prev);
                }
                prev = curr;
            }
            n>>=1;
            curr++;
        }
        return maxi;
    }
};

int main(){
    Solution s;
    cout << s.binaryGap(22) << endl; // Expected output: 2
    cout << s.binaryGap(5) << endl;  // Expected output: 2
    cout << s.binaryGap(6) << endl;  // Expected output: 1
    cout << s.binaryGap(8) << endl;  // Expected output: 0
}