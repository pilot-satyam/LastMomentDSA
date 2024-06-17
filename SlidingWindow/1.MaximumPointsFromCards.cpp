#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum = 0, rSum = 0, maxSum = 0;
        for(int i=0;i<k;i++){
            lSum+=cardPoints[i];
        }
        maxSum = lSum;
        int rightIdx = n-1;
        for(int i = k-1;i>=0;i--){
            lSum = lSum - cardPoints[i];
            rSum = rSum + cardPoints[rightIdx];
            rightIdx = rightIdx - 1;
            maxSum = max(maxSum,lSum+rSum);
        }
        return maxSum;
    }
};

int main(){

}