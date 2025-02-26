#include<bits/stdc++.h>
using namespace std;

long sjf(vector<int> &a){
    sort(a.begin(),a.end());
    int t = 0, wtTime = 0;
    for(int i=0;i<a.size();i++){
        wtTime += t;
        t+=a[i];
    }
    return (wtTime/a.size());
}

int main(){

}