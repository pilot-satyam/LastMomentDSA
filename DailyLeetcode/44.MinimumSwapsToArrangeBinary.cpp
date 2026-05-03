#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/description/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeroes(n);
        //calculting trailing zeroes

        //this for loop covers all the rows from 0 to n
        for(int i=0;i<n;i++){
            int cnt = 0;
            //counting for each row, from right
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 0){
                    cnt++;
                }
                else{
                    // stop when we are hit by 1st 1 from right;
                    break;
                }
            }
            trailingZeroes[i] = cnt;
        }

        int swaps = 0;
        //fixing each position greedily
        for(int i=0;i<n;i++){
            int required = n - 1 - i;
            int j = i;
            while(j<n and trailingZeroes[j] < required) j++;
            if(j == n) return -1;
            //swapping by bring rows back to up
            while(j>i){
                swap(trailingZeroes[j], trailingZeroes[j-1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};