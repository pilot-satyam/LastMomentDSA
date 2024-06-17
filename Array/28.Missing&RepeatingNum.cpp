#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatingNumber(vector<int> &a){
    long long n = a.size();
    long long S = 0, S2 = 0;

    //S - Sn = x - y
    //S2 - S2N = x + y
    long long Sn = (n * (n+1))/2;
    long long S2n  = (n*(n+1)*(2n+1))/6;

    for(int i=0;i<n;i++){
        Sn += a[i];
        S2n = (long long) a[i] * (long long) a[i];

    }

    long long val1 = S - Sn;
    long long val2 = S2 - S2n;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int) x, (int) y};
}

int main(){

}