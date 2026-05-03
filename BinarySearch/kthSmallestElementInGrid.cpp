#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * Q : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/ 
*/

/***

1     5    9 
10    11   13
12.   13.  15

*/

class kthSmallestElement{

private:
    int countIndex(vector<vector<int>> &mat, int n, int index){
        int cnt = 0;
        int row = 0, col = n-1;
        while(row <n and col >=0 ){
            //since we have to find the smallest element to agar
            //present element agar mid se chotha hai then it will move down since left will have only
            // smaller elements hence we will eliminate that search space (by counting all the elemnts of left)
            //for suppose if [0][2] succedds then we will take all 3 elements, if fails trim the col
            // now if [0][1] succedds then we will take remaining 2 elements from the left, 
            //this way eliminating search space
            if(mat[row][col] <= index){
                cnt += col + 1;
                row += 1;
            } 
            else col --;
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cnt = countIndex(matrix,n,mid);
            if(cnt >= k){
                high = mid -1;
            }
            else low = mid + 1;
        }
        return low;
    }
};


int main(){

}