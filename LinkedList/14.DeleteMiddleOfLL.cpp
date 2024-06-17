#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = head->next->next;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

inr main(){

}