//Q: https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2026-04-30

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size()) return false;

        //O(N^2)

        // for(int i=0;i<n;i++){
        //     if(s == goal) return true; 
        //     //saving the first chaar
        //     char first = s[0];
        //     //shifting everything to left
        //     for(int j=0;j<n-1;j++){
        //         s[j] = s[j+1];
        //     }
        //     //putting the first char at end
        //     s[n-1] = first;
        //     cout <<"Transformed s is : " << s << endl;
        //     if(s == goal) return true;
        // }

        //append the string s with itself to figure out any possible rotated string.

        string doubleStr = s + s;
        return doubleStr.find(goal) != string::npos;
    }
};

int main(){
    
}