#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long revNum = 0;
        while(x){
            revNum = revNum * 10 + x%10;
            x/=10;
        }
        if(revNum > INT_MAX or revNum<INT_MIN) return 0;
        return revNum;
    }
};

int main(){

}