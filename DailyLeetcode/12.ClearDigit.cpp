#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10

/**
 * approach is simple, take an answer string and start adding characters while traversing the string
 * and as soon as you encounter a digit then start removing the character from the last of the string
 * because last of the answer has the most recent character.
 * 
 * eg: cb34
 * sol: ans = cb (initially inserted since we haven't encountered a digit, now when we encounter 3 and 4)
 * then we will first remove b and then c. hence ans is ans = ""
 */

//T.C : O(n), S.C : O(1)

class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]) and !ans.empty()){
                ans.pop_back();
            }
            //adding character since digit is not encountered
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};

int main(){

}