#include<bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> &a,int k){
    int xor = 0;
    map<int,int> m;
    m[xor]++; //stores {0,1} initially
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        xor = xor ^ a[i];
        int x = xor ^ k;
        cnt += m[x]; //agar map me x hai to automatically value lelega
        m[xor]++;
    }
    return cnt;
}

int main(){

}