#include<bitstdc++.h>
using namespace std;

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-03

// This recursion is my Solution

/**

3 chars -> a,b,c
if we fix one then we have 2 options to arrange ->  3 * 2 ^ n-1
n = 3 ==> 3 * 2 * 2 = 12 strings

for generation we will generate all strings until k and then and return the ans
*/

// class Solution {

// private:
//     void dfs(string &curr, int n, int &k, string &ans){
//         if(curr.size() == n){
//             k--;
//             if(k == 0) ans = curr;
//             return;
//         }

//         for(char ch : {'a','b','c'}){
//             if(curr.empty() or curr.back() != ch){
//                 curr.push_back(ch);
//                 dfs(curr, n, k, ans);
//                 curr.pop_back();
//                 if(!ans.empty()) return;
//             }
//         }
//     }

// public:
//     string getHappyString(int n, int k) {
//         string ans,curr;
//         dfs(curr, n, k, ans);
//         return ans;
//     }
// };

class Solution{
    public:
    string getHappyString(int n, int k) {
    int total = 3 * pow(2, n - 1);
    if (k > total) return "";

    string ans = "";
    vector<char> alphabet = {'a', 'b', 'c'};
    
    // Adjust k to 0-indexed for easier math
    k--; 

    // Determine 1st character
    int blockSize = pow(2, n - 1);
    ans += alphabet[k / blockSize];
    k %= blockSize;

    // Determine remaining n-1 characters
    for (int i = 1; i < n; i++) {
        blockSize /= 2;
        // Get the two available choices (excluding the last char added)
        vector<char> choices;
        for (char c : alphabet) {
            if (c != ans.back()) choices.push_back(c);
        }
        
        ans += choices[k / blockSize];
        k %= blockSize;
    }

    return ans;
}

};

int main(){
    Solution s;
    cout << s.getHappyString(1, 3) << endl; // Expected output: "c"
    cout << s.getHappyString(1, 4) << endl; // Expected output: ""
    cout << s.getHappyString(3, 9) << endl; // Expected output: "cab"
}
