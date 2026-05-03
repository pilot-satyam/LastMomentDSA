#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty() and st.top().first <= price){
            cnt += st.top().second;
            st.pop();
        }
        //pushing current price with span
        st.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){

}