/**
 * 
 * In this problem we are given two strings and we have to find the minimum number of insertions and deletions required to convert one string into another.
 * Eg : s1 = "heap" , s2 = "pea"
 * 
 *     Here we can delete 'h' and 'a' from s1 and then insert
 *     'a' at the end of s1 to make it equal to s2. Hence the answer is 3.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int lcs(string &s, string &t){
	int m = s.size();
	int n = t.size();
	vector<vector<int>> dp(m+1, vector<int> (n+1,0));
	for(int j=0;j<=n;j++) dp[0][j] = 0;
	for(int i=0;i<=m;i++) dp[i][0] = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}



int canYouMake(string &s1, string &s2){
    return s1.size() + s2.size() - 2 * lcs(s1,s2); 
}

int main(){
    string s1 = "heap";
    string s2 = "pea";
    cout<<canYouMake(s1,s2)<<endl;
    return 0;
}