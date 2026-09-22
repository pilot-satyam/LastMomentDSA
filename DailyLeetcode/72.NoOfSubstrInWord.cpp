//Q : https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/?envType=daily-question&envId=2026-06-29

#include<bitstd/stdc++.h>
using namespace std;

//Easiest Soluttion is to use find string method::
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto p : patterns){
            if(word.find(p) != string::npos) cnt++;
        }
        return cnt;
    }
};

//Second Solution is to use KMP Algorithm to find the substring in the word:

class Solution {

private:
    vector<int> LPS(string pattern){
        int m = pattern.size();
        vector<int> lps(m,0);
        int len = 0;
        for(int i=1;i<m;){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }


private:
    bool KMP(string text, string pattern){
        vector<int> lps = LPS(pattern);
        int i = 0;
        int j = 0;
        while(i < text.size()){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            if(j == pattern.size()) return true;
            else if(i < text.size() and text[i] != pattern[j]){
                if(j == 0) i++;
                else j = lps[j-1];
            }
        }
        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string p : patterns){
            if(KMP(word,p)) ans++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> patterns1 = {"a","abc","bc","d"};
    string word1 = "abc";
    cout << "Number of strings that appear as substrings in word: " << sol.numOfStrings(patterns1, word1) << endl; // Expected output: 3

    vector<string> patterns2 = {"a","b","c"};
    string word2 = "aaaaabbbbb";
    cout << "Number of strings that appear as substrings in word: " << sol.numOfStrings(patterns2, word2) << endl; // Expected output: 2

    vector<string> patterns3 = {"a","a","a"};
    string word3 = "ab";
    cout << "Number of strings that appear as substrings in word: " << sol.numOfStrings(patterns3, word3) << endl; // Expected output: 1

     return 0;
}