#include<bits/stdc++.h>
using namespace std;    

// Q : https://leetcode.com/problems/stone-game-iv/?envType=daily-question&envId=2026-08-10https://leetcode.com/problems/stone-game-iv/?envType=daily-question&envId=2026-08-10


class Solution {

private:
    bool solve(int n, vector<int> &dp){
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];
        for(int i=1;i*i<=n;i++){
            //try removing 1,4,16...
            int remaining = n - i*i;
            //if opponent loses after this move, current player wins
            if(!solve(remaining,dp)){
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }

public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return solve(n,dp);
    }
};

//Iterative DP : 

bool winnerSquareGame(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int stones=1;stones<=n;stones++){
        for(int i=1;i*i <= stones; i++){
            int remaining = stones - i*i;
            if(dp[remaining] == 0){
                dp[stones] = 1;
                break;
            }
        }
    }
    return dp[n];
}


int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.winnerSquareGame(n);
}
