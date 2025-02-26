#include<bits/stdc++.h>
using namespace std;

//Problem: Given a string s and a non-empty string p, 
// find all the start indices of p's anagrams in s. The order of output does not matter.


/**
 *  1)Use a sliding window of size p.length() on string s.
    2)Compare the frequency of characters in the current window with the frequency of characters in p. 
 */

vector<int> findAnagrams(string s,string p){
    unordered_map<char,int> pMap,sMap;
    vector<int> res;

    int n = s.size();
    int m = p.size();

    //base : if P > S not possible return empty
    if(p.size() > s.size()) return res;

    for(char c : p) pMap[c]++;

    for(int i=0;i<p.size();i++){
        sMap[s[i]]++;
    }

    // If the first window is an anagram of 'p', add index 0 to the result
    if (pMap == sMap) res.push_back(0);  

    for(int i = m;i<n;i++){
        sMap[s[i]]++; // Add the character at the right end of the window
        sMap[s[i - m]]--; //removing character that moved out of window frm left
        if(sMap[s[i - m]] == 0) sMap.erase(s[i-m]);// If the count of a character in the map becomes 0, we remove it from the map to keep it clean
        if(pMap == sMap) res.push_back( i - m + 1);
    }
    return res;
}

// in short:
// 1) 'p' ko map me store karo 
// 2) 's' ko initially p length ke barabar s ke map me s ke characters insert karo
// 3) Now check if they are equal
// 4) if they are not equal then slide the window by removing one character from left of current window
// 5) and adding next character in window


int main() {
    string s = "cbaebabacd";  // Given string 's'
    string p = "abc";         // Target string 'p'
    
    // Call the function to find anagrams of 'p' in 's'
    vector<int> result = findAnagrams(s, p);

    // Print the result
    for (int index : result) cout << index << " ";  // Expected output: 0 6
    return 0;
}

