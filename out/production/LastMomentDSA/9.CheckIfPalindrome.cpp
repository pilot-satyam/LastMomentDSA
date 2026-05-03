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
    bool isPalindrome(ListNode* head){
    stack<int> st;
    ListNode* temp = head;
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(temp->val != st.top()){
            return false;
        }
            temp = temp->next;
            st.pop();
        }
         return true;
    }
};

/*
    Optimization using reverse and 2 pointers
*/

class Solution {
public:
     ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        //1st part : finding the middle of LL
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        //2nd part : Reversing the other half LL
        ListNode* newHead = reverseLL(slow->next);

        //3rd part: comparing first half LL and second half LL
        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=NULL){
            if(first->val != second->val){
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;

    }
};

int main(){

}