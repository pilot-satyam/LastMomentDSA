// Q : https://leetcode.com/problems/maximize-active-section-with-trade-i/?envType=daily-question&envId=2026-07-21

/***
 * 
 * Here the intuition is to find the runs of 1's and 0's and then we can trade a run of 1's with two runs of 0's
 * Eg : 100111001 ==> {'1',1} {'0',2} {'1',3} {'0',2} {'1',1}
 * If it follows the pattern 0 | 1 | 0 then we can trade the run of 1's with the two runs of 0's and hence we can increase the number of active sections
 * and the formula to calculate the gain is gain = run_of_0's_left + run_of_0's_right
 * 
 */


#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c : s){
            if(c == '1') ones++;
        }
        int ans = ones;
        //augmenting
        string t = "1" + s + "1";
        vector<pair<char,int>> p; // t = 100111001 ==> {'1',1} {'0',2} {'1',3} {'0',2} {'1',1}

        //to achieve the above beahviour we will maintain cnt
        int cnt = 1;
        for(int i=1;i<t.size();i++){
            if(t[i] == t[i-1]) cnt++;
            else{
                p.push_back({t[i-1],cnt});
                cnt = 1;
            }
        }
        p.push_back({t.back(),cnt});
        //scanning the runs
        for(int i=1;i<p.size()-1;i++){
                if(p[i].first == '1' and p[i-1].first =='0' and p[i+1].first == '0'){
                int gain =  p[i-1].second + p[i+1].second;
                ans = max(ans, ones + gain);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str = "100111001";
    cout<<s.maxActiveSectionsAfterTrade(str)<<endl;
    return 0;
}