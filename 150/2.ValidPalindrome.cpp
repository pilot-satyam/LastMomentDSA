#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

//isalnum() checks if the character is alphanumeric

bool isPalindrome(string s){
    int l = 0, r = s.size()-1;
    while(l<r){
        if(!isalnum(s[l])) l++;
        else if (!isalnum(s[r])) r--;
        else if(tolower(s[l]) != tolower(s[r])) return false;
        else l++, r--;
    }
    return true;
}

int main(){

}