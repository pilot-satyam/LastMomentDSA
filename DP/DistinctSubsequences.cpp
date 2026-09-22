#include<bits/stdc++.h>
using namespace std;

class Solution {

//0 based indexing work but for converting it into tabulation we use 1 based 
//indexing since i or j can reach negative hence will add +1 for eveything

//0 based indexing memoization
private:
    int solve(int i, int j, string &s, string &t,vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }

// 1 based indexing memoization
    int solve1(int i, int j, string &s, string &t,vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //since earlier we were comparing i and j with 0 based indexing 
        //hence we were using s[i] and t[j] but now we are using 1 based indexing hence we will use s[i-1] and t[j-1] hence 
        //will compare prev character of both strings. 
        if(s[i-1] == t[j-1]){ 
            return dp[i][j] = solve1(i-1,j-1,s,t,dp) + solve1(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve1(i-1,j,s,t,dp);
    }

//tabulation 

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int j=1;j<=m;j++) dp[0][j] = 0; //we can omit this line since we have already initialized the dp array with 0
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }

    //space optimization
    public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> curr(m+1,0), prev(m+1,0);
        prev[0] = curr[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return (int)prev[m];
    }

    // 1 D optimised space 
    public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1,0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        //since i or j can reach negative hence will add +1 for eveything
        return solve(n,m,s,t,dp);
    }
};

int main(){
    Solution s;
    string str1 = "rabbbit";
    string str2 = "rabbit";
    cout<<s.numDistinct(str1,str2)<<endl;
    return 0;
}