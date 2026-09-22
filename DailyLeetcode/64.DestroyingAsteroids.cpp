// Q : https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31 

#include<bitstd/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum = mass;
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(sum < asteroids[i]) return false;
            sum += asteroids[i];
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> asteroids1 = {5, 10, 15};
    cout << sol.asteroidsDestroyed(10, asteroids1) << endl; // Expected output: true

    vector<int> asteroids2 = {3, 9, 19, 5, 21};
    cout << sol.asteroidsDestroyed(10, asteroids2) << endl; // Expected output: false

    vector<int> asteroids3 = {1, 2, 3, 4};
    cout << sol.asteroidsDestroyed(1, asteroids3) << endl; // Expected output: true

    return 0;
}