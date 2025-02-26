#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s,string t){
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> m;
    for(char c : s){
        m[c]++;
    }
    for(char c : t){
        if(m.find(c) == m.end() || m[c] == 0){
            return false;
        }
        m[c]--; //it means we have already find it in map and hence we need to subtract it since one matching has been done already
    }
    return true;
}


int main(){

}