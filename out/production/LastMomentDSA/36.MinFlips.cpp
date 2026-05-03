#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/solutions/479998/c-bitwise-xor-solution-1-line/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int minFlips(int a, int b, int c) {
    return popcount<uint>(c ^= a | b) + popcount<uint>(a & b & c);
}
};

int main(){

}