#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){ //O(n)
            if(s[i] == '*'){
                if(!st.empty()){
                    st.pop();//removing previous character
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){ //O(n)
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end()); //log(n)
        return ans;
    }
};

//Optimized code: using two pointer

class Solution {
public:
    string removeStars(string s) {
        int right = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '*'){
                if(right > 0){
                    right--; //removing last char
                }
            }
            else{
                s[right] = s[i]; //writing valid char at next position
                right++;
            }
        }
        return s.substr(0,right);
    }
};

/**
DRY RUN: 
l --> right = 1;
e --> right = 2;
e --> right = 3;
t --> right = 4;
* --> right = 3;(remove previous)
* --> right = 2(remove previous);
c --> right = 3;
o --> right = 4;
d --> right = 5;
* --> right = 4;(remove prev)
e --> right = 5;

s.substr(0,right) = lecoe
*/

int main(){

}