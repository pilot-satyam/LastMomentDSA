/*
Approach & Intuition:

Given a binary string representing a number, the goal is to reduce it to '1' using the following operations:
1. If the number is even (ends with '0'), divide it by 2 (remove the last bit).
2. If the number is odd (ends with '1'), add 1 to it (handle binary addition with carry).
Repeat these steps until the string becomes '1'.

Intuition:
- When the number is even, dividing by 2 is straightforward (just pop the last bit).
- When the number is odd, adding 1 may cause a carry that can propagate leftwards, possibly increasing the string's length.
- The process mimics how you would manually reduce a binary number to 1, step by step, using only the allowed operations.

Explanation of Solution:
- The solution uses two helper functions:
    - divideByTwo: Removes the last character of the string (equivalent to dividing by 2).
    - addOne: Simulates binary addition of 1, handling carries as needed.
- In the main function (numSteps), we loop until the string is reduced to '1'.
    - If the last bit is '0', we divide by two.
    - If the last bit is '1', we add one.
    - We count each operation.
- The process continues until only '1' remains, and the count is returned.

Time Complexity: O(N^2) in the worst case, where N is the length of the string, due to repeated string operations and possible carries.
Space Complexity: O(N) for the string manipulation.
*/
#include<bits/stdc++.h>
using namespace std;

//Q:https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2026-02-19

class Solution {

private:
    void divideByTwo(string &s){
        s.pop_back();
    }


    /*
    addOne function explanation:
    - This function simulates adding 1 to a binary number represented as a string.
    - It starts from the least significant bit (rightmost character).
    - If the bit is '1', it becomes '0' (since 1+1=0 with a carry of 1), and the carry is propagated to the next bit to the left.
    - This continues until a '0' is found, which is then changed to '1' (since 0+1=1, and no further carry is needed).
    - If all bits are '1', the function prepends '1' to the string (e.g., '111' + 1 = '1000').
    - This mimics the manual process of binary addition with carry.
    */
    void addOne(string &s){
        int i = s.size() - 1;
        // iterating while char is 1 and changing to 0 to carry 1
        while(i>=0 and s[i]!='0'){
            s[i] = '0';
            i--;
        }
        if(i<0){
            s = '1' + s;
        } else{
            s[i] = '1';
        }
    }

public:
    int numSteps(string s) {
        int n = s.size();
        int cnt = 0;
        while(s.size() > 1){
            n = s.size();
            if(s[n - 1] == '0'){
                divideByTwo(s);
            }
            else{
                addOne(s);
            }
            cnt++;
        }
        return cnt;
    }
};

/*
numNewSteps function explanation:
--------------------------------
Approach & Intuition:
- This function optimizes the process of reducing a binary string to '1' by simulating the steps mathematically, without modifying the string.
- It traverses the string from right to left (least significant bit to most significant, ignoring the first bit since we stop at '1').
- It uses a carry variable to account for the effect of previous additions.

How it works:
- For each bit (from right to left, except the leftmost):
    - If the current bit (plus carry) is even, only one step is needed (divide by 2).
    - If the current bit (plus carry) is odd, two steps are needed (add 1, then divide by 2), and a carry is set for the next bit.
- The process continues until the most significant bit is reached.
- At the end, if there is a carry left, it is added to the total steps.

Why is this efficient?
- It avoids string manipulation and simulates the process using arithmetic, making it faster and more space-efficient.

Time Complexity: O(N), where N is the length of the string.
Space Complexity: O(1), only a few variables are used.
*/
int numNewSteps(string s) {
    int steps = 0;
    int carry = 0;

    // traverse from right to left (ignore MSB at index 0)
    for(int i = s.size() - 1; i > 0; i--) {

        int bit = (s[i] - '0') + carry;

        if(bit % 2 == 0) {
            // even
            steps += 1;
        } else {
            // odd
            steps += 2;
            carry = 1;
        }
    }

    return steps + carry;
}

int main(){
    Solution s;
    cout << s.numSteps("1101") << endl; // Expected output: 6
    cout << s.numSteps("10") << endl;   // Expected output: 1
    cout << s.numSteps("1") << endl;    // Expected output: 0
}
