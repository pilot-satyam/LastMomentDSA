#include<bits/stdc++.h>
using namespace std;

class Solution {

private: 
    void solve(int idx,string &s, string &temp, vector<string> &ans,unordered_map<char,string> &m){

        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        string str = m[s[idx]]; // m[2] ==> abc
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            solve(idx+1,s,temp,ans,m);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        if(digits == "") return ans;
        unordered_map<char,string> m; // 2 -> abc 
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        solve(0,digits,temp,ans,m);
        return ans;
    }
};

int main(){

}