//Q: https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        //first we'll move the stones to right
        for(int i=0;i<m;i++){
            int write = n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j] == '*'){
                    write = j-1; //after obstacle reset it 
                }
                else if(boxGrid[i][j] == '#'){
                    swap(boxGrid[i][j],boxGrid[i][write]);
                    write--;
                }
            }
        }
        vector<vector<char>> ans(n,vector<char> (m));
        //rotating 90º 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m-1-i] = boxGrid[i][j];
            }
        }
    return ans;
    }
};

int main(){
    
}