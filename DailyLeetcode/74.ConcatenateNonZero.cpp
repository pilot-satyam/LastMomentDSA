// Q : https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/?envType=daily-question&envId=2026-07-07

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//         string s = to_string(n);
//         long long x = 0;
//         long long sum = 0;
//         for(auto c : s){
//             if(c != '0'){
//                 int digit = c - '0';
//                 x = (x * 10) + digit;
//                 sum += digit;
//             }
//         }
//         return (x*sum);
//     }
// };

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, pow10 = 1;
        while (n > 0) {
            int d = n % 10;
            sum += d;
            if (d > 0) {
                x += d * pow10;
                pow10 *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};

int main(){
    Solution s;
    int n = 123405;
    cout<<s.sumAndMultiply(n)<<endl;
    return 0;
}