#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long temp = x;
        long revNum = 0;
        while(temp){
            revNum = revNum*10 + temp %10;
            temp/=10;
        }
        return (revNum == x);
    }
};

int main(){

}