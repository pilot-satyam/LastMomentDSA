#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/total-cost-to-hire-k-workers/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0;
        int n = costs.size();
        int left = 0, right = n-1;
        priority_queue<long long, vector<long long>, greater<long long>> leftPQ,rightPQ;

        //adding initial candiates element
        for(int i=0;i<candidates && left<=right;i++){
            leftPQ.push(costs[left]);
            left++;
            if(left<=right){
                rightPQ.push(costs[right]);
                right--;
            }
        }

        //hiring k workers
        for(long long i=0;i<k;i++){
            if(!leftPQ.empty() && (rightPQ.empty() || leftPQ.top() <= rightPQ.top())){
                res += leftPQ.top();
                leftPQ.pop();
                //adding next left candiate if avialable
                if(left <= right){
                    leftPQ.push(costs[left]);
                    left++;
                }
            }
            else{
                res += rightPQ.top();
                rightPQ.pop();
                if(left <= right){
                    rightPQ.push(costs[right]);
                    right--;
                }
            }
        }
        return res;
    }
};
int main(){

}