#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/?envType=daily-question&envId=2026-03-03

/**
 * 
 * Remember:
            So you have these choices:

            Only flip bits

            Only rotate

            Rotate + flip

            Flip + rotate

            But the goal is to minimize Type-2 operations (flips).

            💡 Key insight:
            Rotation is free (it does not count toward the answer).
            So we can rotate as many times as we want to reduce flips.

            Therefore the problem becomes:

            Among all possible rotations of the string, find the one that requires the minimum flips to become alternating.
        * 
 */

// ======================= METHOD 1 =======================
/*
APPROACH (Sliding Window + Explicit Alternating Strings)

Goal:
Make the binary string alternating using the minimum number of flips.
Rotation is free (Type-1 operation), so we try every possible rotation.

Key Observations:
1. Only TWO valid alternating patterns exist:
      Pattern1: 010101...
      Pattern2: 101010...

2. To simulate all rotations efficiently:
      Instead of rotating the string repeatedly,
      we double the string:  t = s + s

   Example:
      s = "1100"
      t = "11001100"

   Every substring of length n in t represents a rotation of s.

3. Use a sliding window of size n over t.

4. Track mismatches with both patterns:
      diff1 → flips needed to match pattern1
      diff2 → flips needed to match pattern2

5. When window exceeds size n:
      remove contribution of the left character.

Time Complexity  : O(n)
Space Complexity : O(n) (because of t, alt1, alt2 strings)
*/

// class Solution {
// public:
//     int minFlips(string s) {

//         int n = s.size();

//         // Double the string to simulate all rotations
//         string t = s + s;

//         // Create alternating patterns for comparison
//         string alt1 = "", alt2 = "";

//         for(int i = 0; i < 2*n; i++){
//             // Pattern1: 101010...
//             alt1 += (i % 2) ? '0' : '1';

//             // Pattern2: 010101...
//             alt2 += (i % 2) ? '1' : '0';
//         }

//         int diff1 = 0, diff2 = 0;
//         int res = INT_MAX;
//         int left = 0;

//         // Sliding window across doubled string
//         for(int right = 0; right < 2*n; right++){

//             // Add new character mismatch contribution
//             if(t[right] != alt1[right]) diff1++;
//             if(t[right] != alt2[right]) diff2++;

//             // Maintain window size <= n
//             if(right - left + 1 > n){

//                 // Remove mismatch contribution of outgoing char
//                 if(t[left] != alt1[left]) diff1--;
//                 if(t[left] != alt2[left]) diff2--;

//                 left++;
//             }

//             // When window size == n → represents one rotation
//             if(right - left + 1 == n)
//                 res = min(res, min(diff1, diff2));
//         }

//         return res;
//     }
// };



// ======================= METHOD 2 (OPTIMIZED) =======================
/*
APPROACH (Sliding Window + Circular String Trick)

Optimization Ideas:
1. We DO NOT need to store:
      - doubled string
      - alternating strings

2. Instead simulate circular string using:
      s[i % n]

3. Alternating pattern can be computed using index parity:
      if index % 2 == 0 → even index
      if index % 2 == 1 → odd index

Pattern1: 010101...
Pattern2: 101010...

4. Sliding window still runs from [0 ... 2n-1]
   to simulate all rotations.

5. When a new character enters window:
      update mismatch counts

6. When window exceeds size n:
      remove mismatch contribution of left character

Time Complexity  : O(n)
Space Complexity : O(1)  (no extra arrays or strings)
*/

class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        int diff1 = 0, diff2 = 0;   // mismatch counts for both patterns
        int left = 0;
        int res = INT_MAX;

        // simulate scanning s+s without actually building it
        for(int right = 0; right < 2*n; right++){

            // current character in circular string
            char c = s[right % n];

            // expected chars for both patterns
            char expected1 = (right % 2) ? '1' : '0';  // pattern 0101...
            char expected2 = (right % 2) ? '0' : '1';  // pattern 1010...

            // update mismatch counts when character enters window
            if(c != expected1) diff1++;
            if(c != expected2) diff2++;

            // shrink window if size exceeds n
            if(right - left + 1 > n){

                char leftChar = s[left % n];

                // expected chars at left index
                char exp1 = (left % 2) ? '1' : '0';
                char exp2 = (left % 2) ? '0' : '1';

                // remove mismatch contribution
                if(leftChar != exp1) diff1--;
                if(leftChar != exp2) diff2--;

                left++;
            }

            // window size n → represents one rotation
            if(right - left + 1 == n){
                res = min(res, min(diff1, diff2));
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    cout << s.minFlips("111000") << endl; // Expected output: 1
    cout << s.minFlips("010") << endl;    // Expected output: 0
    cout << s.minFlips("1110") << endl;   // Expected output: 1
}