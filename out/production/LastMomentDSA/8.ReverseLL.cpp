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

            /*

            RECURSIVE SOLUTION

            */
    ListNode* reverseList(ListNode* head) {

        //BASE CASE
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    /*
    
    ITERATIVE SOLUTION
    
    */

   ListNode* reverseList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp; //temp ko hum prev ko assign karnege
        temp = front; //front ko hum temp ko assign karnege
    }
    return prev;
   }
};

int main(){

}