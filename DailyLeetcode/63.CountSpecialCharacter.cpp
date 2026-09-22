//Q : https://leetcode.com/problems/count-the-number-of-special-characters-ii/?envType=daily-question&envId=2026-05-27 

#include<bitstd/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int cnt = 0;
        vector<int> lCase(26, -1);
        vector<int> uCase(26, -1);
        for(int i=0;i<n;i++){
            char ch = word[i];
            if(ch >= 'a' and ch <= 'z'){
                lCase[ch - 'a'] = i;
            }
            else if(ch >= 'A' and ch <= 'Z'){
                if(uCase[ch - 'A'] == -1){
                    uCase[ch - 'A'] = i;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(lCase[i] != -1 and uCase[i] != -1){
                if(lCase[i] < uCase[i]) cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    cout << sol.numberOfSpecialChars("aaAbcBC") << endl; // Expected output: 3
    cout << sol.numberOfSpecialChars("abc") << endl;     // Expected output: 0
    cout << sol.numberOfSpecialChars("AbC") << endl;     // Expected output: 1
    return 0;
}