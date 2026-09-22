#include<bits/stdc++.h>
using namespace std;

class LongestCommonSubsequence {

private:
    int solve(int i, int j, string text1, string text2,vector<vector<int>> &dp){
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return dp[i][j] = 1 + solve(i-1,j-1,text1,text2,dp);
        return dp[i][j] =  max(solve(i-1,j,text1,text2,dp), solve(i,j-1,text1,text2,dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return solve(n-1,m-1,text1,text2,dp); ==> Memoization
        //shifting of states
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// Space Optimization

 int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return solve(n-1,m-1,text1,text2,dp); ==> Memoization
        //shifting of states
        vector<int> curr(m+1,0), prev(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = 0;
        for(int i=0;i<=n;i++) curr[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] =  max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }

int main(){
    LongestCommonSubsequence lcs;
    string text1 = "abcde";
    string text2 = "ace";
    cout<<lcs.longestCommonSubsequence(text1,text2)<<endl;
    return 0;
}