#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/counting-bits/description/?envType=study-plan-v2&envId=leetcode-75

/**
 * Concept:Bitwise AND (&)
The AND operation between two bits returns 1 only if both bits are 1. Otherwise, it returns 0. 
This operation is commonly used to extract specific bits from a number.

Bitwise Right Shift (>>)
Shifting the bits of a number to the right (>>) effectively divides the number by 2. 
This is useful when we want to isolate the bits of a number and process them one by one.

Popcount (Number of Set Bits)
A powerful approach is to note that the number of set bits in a number x can be derived from 
its lower bits. The key observation is:
 */

/*
Intuition: Dynamic Programming Approach
We can use a dynamic programming approach, where the result for i (the number of set bits for i)
can be derived from the result for i / 2 (integer division).

The key observation here is:

If i is even, the number of set bits in i is the same as the number of set bits in i / 2 because shifting i right by 1 bit does not change the number of set bits.

If i is odd, then the number of set bits in i is 1 more than the number of set bits in i / 2 because the least significant bit is set (1).
Thus, we can use the formula:

dp[i] = dp[i >> 1] + (i & 1)
Where:

dp[i >> 1] gives the number of set bits for i // 2 (i.e., shifting right by 1 bit).
(i & 1) adds 1 if i is odd (i.e., if the least significant bit is 1).
*/

//Right Shift

/*
The rightmost bit (1 in 101) is removed, and all the other bits shift to the right by one position. 
This process is like dividing the number by 2 and discarding the remainder.
eg: 100 (original binary for 4)
becomes
010 (after shifting right by 1 position)

****** kuch nai bas right shift karna hai last ka digit delete karke staring me 0 add karna hai ******
*/


/*
If you shift a number to the right, you are essentially:

Dividing the number by 2^n, where n is the number of positions you shift.
Dropping any extra information that falls off the end.
For example:

5 >> 1 is the same as dividing 5 by 2, which results in 2.
7 >> 2 is the same as dividing 7 by 4 (since 2^2 = 4), which results in 1.
*/

/**
 * Why Use Right Shifting?
In the context of the problem we’re solving, right shifting helps us understand
how many bits are in a number without worrying about the exact details. We can compute
the number of set bits (1's) by breaking the number down and repeatedly halving it.
 */


/****

MOST IMPORTANT: 
 
Why use i >> 1?

Right shifting (i >> 1) means you’re looking at i // 2. This gives you the same number of set bits
as the number i without the least significant bit.
Example: For i = 5, the binary representation is 101. If we shift 5 right by one position (i >> 1), 
we get 2, which is 10 in binary. The number of set bits in 5 (which is 101) is the 
same as the number of set bits in 2 (10), plus one more if i is odd.


Why use i & 1?

Bitwise AND (i & 1) checks if the least significant bit of i is 1 or 0.
If the least significant bit is 1 (i.e., i is odd), then i & 1 will be 1.
If the least significant bit is 0 (i.e., i is even), then i & 1 will be 0.
This helps us decide whether we need to add 1 to the count of set bits for that number
*/
int main(){

}