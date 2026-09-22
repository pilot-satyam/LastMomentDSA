#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/rotate-image/description/?envType=daily-question&envId=2026-05-04 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
                cout <<" transposed matrix : "  << matrix[i][j] << " " << endl;
            }
        }
        //reverse each row after transposing
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){

}