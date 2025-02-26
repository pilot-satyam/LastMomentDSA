#include<bits/stdc++.h>
using namespace std;

string compressString(string s){
    int n = s.size();
    if(n == 0) return s;
    string ans = "";
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1]){
            cnt++;
        }
        else{
            ans += s[i-1] + to_string(cnt); //aabbc here now since i=2 (b) but not equal to i=1 (a),so we will be appending the previous character with it's count
            cnt = 1;
        }
    }
    ans += s[n-1] + to_string(cnt); // for the last character in string
    return ans.size() < n ? ans : s;
}

int main() {
    string s = "aabcccccaaa";
    cout << compressString(s) << endl;  // Output: "a2b1c5a3"
    return 0;
}