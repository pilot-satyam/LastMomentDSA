#include<bits/stdc++.h>
using namspace std;

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

    ListNode* reverseLL(ListNode* temp){
        if(temp == NULL || temp->next ==NULL) return temp;
        ListNode* newHead = reverseLL(temp->next);
        ListNode* front = temp->next;
        front->next = temp;
        temp->next = NULL;
        return newHead;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        // k-=1;
        while(temp!=NULL and k>1){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp!=NULL){
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};

int main(){

}