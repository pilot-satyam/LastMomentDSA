#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
 * 
 */

class Solution {
public:
   int compress(vector<char>& chars) {
       int n = chars.size();
       int write = 0, read = 0;  // `write` is for modifying the array in place, `read` is for iterating.
       while (read < n) {
           char current_char = chars[read];  // Current character
           int count = 0;
           // Count occurrences of the current character
           while (read < n && chars[read] == current_char) {
               read++;
               count++;//a = 2
           }
           // Write the character
           chars[write++] = current_char; //chars[write++] ='a' ->write = 1
           // Write the count if greater than 1
           if (count > 1) {
               string count_str = to_string(count);
               for (char c : count_str) {
                // Write each digit of the count,
                //chars[write++] = '2' -> write = 2 [a,2,b,b,c,c,c]
                   chars[write++] = c;  
               }
           }
       }
       return write;  // New length of the array
   }
};

int main(){

}