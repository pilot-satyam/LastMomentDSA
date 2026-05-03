#include<bits/stdc++.h>
using namespace std;
//My Article
// https://leetcode.com/problems/decode-string/solutions/6257302/detailed-intuition-solution-along-with-t-xqtm

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentString = "";
        int currentNum = 0; //for storing current multiplier
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                currentNum = currentNum * 10 + (c - '0'); //for identifying double digits like 12
            }
            else if(c == '['){
                numStack.push(currentNum);
                strStack.push(currentString);
                currentString = "";
                currentNum = 0;
            }
            else if(c == ']'){
                //decoding string
                string decodedString = currentString;
                currentString = strStack.top(); //getting previous string
                strStack.pop();

                int repeatingTimes = numStack.top();
                numStack.pop();

                //repeat decoded segment and append prev string
                for(int i=0;i<repeatingTimes;i++){
                    currentString += decodedString;
                }
            }else{
                //add characters to current substring
                currentString += c;
            }
        }
        return currentString;
    }
};

int main(){
}