#include<bits/stdc++.h>
using namespace std; 


// Q: https://leetcode.com/problems/champagne-tower/?envType=daily-question&envId=2026-02-14

/*
Intuition:
We want to find out how much champagne is in a specific glass after pouring a certain amount into the top glass of a pyramid, where each glass can hold 1 unit and any overflow splits equally to the two glasses below.

Approach:
- Use recursion with memoization (DP) to compute the amount in each glass.
- For glass at (i, j), its content comes from the overflow of the two glasses above it: (i-1, j-1) and (i-1, j).
- If the glass above has more than 1 unit, the excess is split equally to the two glasses below.
- Base case: The top glass (0, 0) gets all the poured champagne.
- For each glass, sum the contributions from both possible overflows.
- The answer is the minimum of 1.0 and the computed value (since a glass can't hold more than 1 unit).

Why (left-1)/2 and (right-1)/2?
If a glass above (left or right) has more than 1 unit, only the excess (left-1 or right-1) overflows, and it splits equally to the two glasses below, so each gets half of the overflow.

Dry Run Example:
Suppose poured = 2, query_row = 1, query_glass = 1
Level 0: [2] (top glass)
    - It can hold 1, so 1 overflows down.
Level 1: [0.5, 0.5] (each gets half of the overflow)
    - So, glass (1,1) has 0.5 units.
Result: min(1.0, 0.5) = 0.5
*/

class Solution {
private:
    double minGlass(int i, int j, int poured, vector<vector<double>> &dp){
        if(j<0 or j>i) return 0.0;
        //top glass
        if(i==0 and j==0) return poured;
        if(dp[i][j] != -1.0) return dp[i][j];
        double left = minGlass(i-1,j-1,poured,dp);
        double right = minGlass(i-1,j,poured,dp);
        double total = 0.0;
        if(left > 1) total += (left-1) / 2.0;
        if(right > 1) total += (right - 1) / 2.0;
        return dp[i][j] = total;
    }

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101.0 ,vector<double> (101.0,-1));
        return min(1.0, minGlass(query_row, query_glass,poured,dp));
    }
};

//Tabulation approach::

double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101.0 ,vector<double> (101.0,0.0));
        dp[0][0] = poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j] > 1.0){
                    double overflow = (dp[i][j] - 1.0) / 2.0;
                    dp[i+1][j] += overflow;
                    dp[i+1][j+1] += overflow;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }

int main(){
    
}
