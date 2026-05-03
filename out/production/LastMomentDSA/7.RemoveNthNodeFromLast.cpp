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

//initially first pointer ko upto n tk chala do
// next agar fast pointer exist karta hai to move fast and slow pointer simultaneously
// slow head se start hoga kyunki wahi pe hai wo but farst hamara n ke baad se start hoga
// end me when you will reach end node, return slow -> next to deleteNode and change link to next->next
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
    if(fast == NULL) return head->next;
    while(fast->next!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* delNode = slow->next;
    slow->next = slow->next->next; //storing the address of next Node and then deleting the targeted Node
    delete(delNode);
    return head;
}

};

int main(){

}