##include<bits/stdc++.h>
using namespace std;

class Solution {

private:
    int helper(int n){
        int nextNumber = 0;
        while(n > 0){
        int digit = n % 10;
        n/=10;
        nextNumber += digit * digit; // 19 ==> 81 + 1 ==> 82 ==> 4 + 64 ==> 68 ==> 64 + 36 ==> 100 ==> 1
        }
        return nextNumber;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        //keep looping forever unitl one of the conditions do not match:
        //1. if fast reaches 1 ==> happy number
        //2. if fast == slow ==> cycle found ==> stop
        while(true){
            slow = helper(slow);
            fast = helper(helper(fast));
            if(fast == 1) return true;
            if(fast == slow) return false;
        }
    }
};

int main(){
}