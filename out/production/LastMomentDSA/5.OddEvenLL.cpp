#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(even!=NULL and even->next!=NULL){
            odd->next = odd->next->next; //determining what will be the next index
            even->next = even->next->next;
            odd = odd->next; //to go to next index
            even = even->next; // same as above
        }
        odd->next = evenHead;
        return head;
    }
};

int main(){

}