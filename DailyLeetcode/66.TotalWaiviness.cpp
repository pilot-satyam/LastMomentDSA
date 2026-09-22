// Q : https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/?envType=daily-question&envId=2026-06-04 

#include<bitstd/stdc++.h>
using namespace std;

// class Solution {
// private:
//     int getWaviness(int x) {
//         string s = to_string(x);
//         int waviness = 0;
//         int n = s.size();

//         for (int i = 1; i < n - 1; i++) {
//             if ((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1])) {
//                 waviness++;
//             }
//         }
//         return waviness;
//     }

// public:
//     int totalWaviness(int num1, int num2) {
//         int total = 0;
//         for (int i = num1; i <= num2; i++) {
//             total += getWaviness(i);
//         }
//         return total;
//     }
// };


class Solution {
private:
    int getWaviness(int x) {
        int waviness = 0;
        
        // Numbers with fewer than 3 digits cannot have peaks or valleys
        if (x < 100) return 0; 

        // Extract the first three digits from the right
        int right = x % 10;   x /= 10;
        int mid = x % 10;     x /= 10;

        while (x > 0) {
            int left = x % 10; // Current left digit
            
            // Check peak or valley math
            if ((mid > left && mid > right) || (mid < left && mid < right)) {
                waviness++;
            }

            // Shift positions to the left for the next check
            right = mid;
            mid = left;
            x /= 10;
        }
        return waviness;q
    }

public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; i++) {
            total += getWaviness(i);
        }
        return total;
    }
};

int main(){
    Solution sol;
    cout << sol.totalWaviness(1, 100) << endl; // Expected output: 0
    cout << sol.totalWaviness(100, 200) << endl; // Expected output: 9
    cout << sol.totalWaviness(123, 321) << endl; // Expected output: 12
    return 0;
}   