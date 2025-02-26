#include<bits/stdc++.h>
using namespace std;

/**
 * PAYPALISHIRING, numRows = 3
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * PAYPALISHIRING, numRows = 4 ==> PINALSIGYAHRPI
 * 
 * P        I           N
 * A    L   S      I    G
 * Y  A     H   R
 * P        I
 */

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        if(numRows == 1 or numRows > s.length()){
            return s;
        }
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goDown = false;

        for(char c : s){
            rows[currentRow] += c;
            if(currentRow == 0 or currentRow == numRows - 1){
                goDown = !goDown;
            }
            currentRow += goDown ? 1 : -1;
        }

        for(auto row : rows){
            result += row;
        }
        return result;
    }
};


int main(){

}