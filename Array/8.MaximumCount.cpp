#include<bits/stdc++.h>
using namespace std;

/*
In the array of 0's and 1's we need to find out the maximum number of times the consecutive 1's are occuring
Eg. [1,0,1,1,0,1,1,1,1,0,1] --> Here the ans = 4 
*/

/*
Sol: We will keep a counter and whenever 1 is encountered increase the counter by 1 and when 0 is encounterd 
save the valur in maxi.
*/

int countNumberOne(vector<int> a,int n){
    int cnt=0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
}

int main()
{

}