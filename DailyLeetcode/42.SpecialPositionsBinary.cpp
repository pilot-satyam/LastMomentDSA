#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-03

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        vector<int> cntRows(n,0);
        vector<int> cntCols (m,0);

        //storing frequency
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    cntRows[i]++;
                    cntCols[j]++;
                }
            }
        }
        //checking special
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 and cntRows[i]==1 and cntCols[j] == 1) cnt++;
            }
        }
        return cnt;
    }
};