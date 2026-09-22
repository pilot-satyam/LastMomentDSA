//Q : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include<bits/stdc++.h>
using namespace std;

/***
 * 
 * 
 * Here the intuition to take the longest palindrome in current string
 * and then subtrsct it from total lenght, since we saw in longest palindomic subsequence
 * we take a string and its reverse and then find the longest common subsequence between them 
 * 
 * eg : "mbadm" -> LONGEST PALINDROMIC SUBSEQUENCE = mam
 *      n = 5 LPS = 3 hence ans = 5 - 3 = 2 , because the logic is we havw to insert 'bd' but in reverse
 *      order like this mbd a db m 
 * 
 */

class Solution {

private:
    int lcs(string &s, string &t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        return dp[n][m];
    }

private:
    int longestPalindromeSubsequence(string &s){
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s,t);
    }

public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubsequence(s);
    }
};

int main(){
    Solution s;
    string str = "mbadm";
    cout<<s.minInsertions(str)<<endl;
    return 0;
}