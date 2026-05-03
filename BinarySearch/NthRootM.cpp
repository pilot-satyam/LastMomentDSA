#include<bits/stdc++.h>
using namespace std;

//https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=PROBLEM
/**

 A : The intuition remains same as of finding square root, the only condition we have been introduced over here is that
     the nth root could be any number like 4 and multiplication could be very big and exceed long long size, hence we slightly
     modify our code. We check if after multiplication the number exceeds 'm' we immediately return from there and do not store
     the value, hence we saved overflow. Now accordingly our main function calculates the value.

     Eg : Start multiplying: 100000 * 100000 = 10,000,000,000 (and if this goes on then computer will crash)
          Wait! Is 10,000,000,000 > m (which is 10)?
          YES → We already know it's too large!
          STOP! Don't multiply further.

 */

int solve(int mid, int n, int m){
  long long ans = 1;
  for(int i=1;i<=n;i++){
    ans = ans * mid;
    if(ans > m) return 2;
  }
    if(ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
  int low = 1, high = m;
  while(low <= high){
    int mid = low + (high - low)/2;
    int midN = solve(mid,n, m);
    if(midN == 1) return mid;
    else if(midN == 0) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int main(){
}