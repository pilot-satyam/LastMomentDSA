#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/smallest-number-in-infinite-set/?envType=study-plan-v2&envId=leetcode-75

class SmallestInfiniteSet {
    set<int> s;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int element = *s.begin();
        s.erase(s.begin());
        return element;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

int main(){

}