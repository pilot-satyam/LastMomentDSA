#include<bits/stdc++.h>
using namespace std;

//recursive solution

class Solution {
private:
   void solve(int idx, string &tiles, unordered_set<string> &ans, string current) {
       if (!current.empty()) {
           ans.insert(current);
       }
       if (idx == tiles.size()) {
           return;
       }
       for (int i = idx; i < tiles.size(); i++) {
           swap(tiles[idx], tiles[i]);  // Swap to generate permutations
           solve(idx + 1, tiles, ans, current + tiles[idx]);
           swap(tiles[idx], tiles[i]);  // Backtrack
       }
   }
public:
   int numTilePossibilities(string tiles) {
       unordered_set<string> ans;  // Set to store unique sequences
       solve(0, tiles, ans, "");
       return ans.size();
   }
};

int main(){

}