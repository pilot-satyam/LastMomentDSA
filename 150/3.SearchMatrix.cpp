#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    bool search(vector<vector<int>> &matrix, int x)
{
   int  n = matrix.size();
   int  m = matrix[0].size();

   int  row  = 0, col = m-1;

   while(row < n and col >= 0){
       if(matrix[row][col] == x) return true;
       else if(matrix[row][col] > x) col--;
       else row++;
   }
   return false;
}

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() or  matrix[0].empty()) return false;
        return search(matrix,target);
    }
};

int main(){

}