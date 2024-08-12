#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxLen=0;
        unordered_map<int,int> m;
        while(r < fruits.size()){
            m[fruits[r]]++;
            if(m.size() > 2){
                m[fruits[l]]--;
                if(m[fruits[l]] == 0) {
                    m.erase(fruits[l]);
                }
                l++;
            }
            if(m.size() <= 2){
            maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};

int main(){

}