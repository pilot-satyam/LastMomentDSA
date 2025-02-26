#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/frog-jump_3621012
//recursive --> top down
int f(int ind,vector<int> &heights,vector<int> &dp)
{
    if(ind == 0)
        return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left =f(ind-1,heights,dp)+abs(heights[ind] - heights[ind-1]) ;
    int right = INT_MAX;
    if(ind > 1)
        right = f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    return dp[ind] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return f(n-1,heights,dp);
}

/*
Iterative --> bottom up
*/

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int left = dp[i-1]+ abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
        right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

/*
space optimized 
*/

int frogJump(int n, vector<int> &heights)
{
    int prev = 0, prev2 = 0;
    for(int i=1;i<n;i++){
        int left = prev + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
        right = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curi = min(left,right);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main(){

}