#include<bits/stdc++.h>
using namespace std;

int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next; // kyunki humko pata chal chuka hai ki cycle hai to every node ko count karne ke liye we will increase fast by 1.
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLength(slow,fast);
        }
    }
}

int main(){

}