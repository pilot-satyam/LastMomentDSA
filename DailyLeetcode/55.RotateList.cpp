//https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or head->next == NULL or k == 0) return head;
        ListNode* temp = head;
        int n = 1;
        while(temp->next){
            temp = temp->next;
            n++;
        }

        // since rotation need to optimize k
        k = k%n;
        if(k==0) return head;

        //making it circular
        temp->next = head;

        //finding new tail
        int stepsToNewTail = n-k;
        ListNode* newTail = head;
        for(int i=1;i<stepsToNewTail;i++){
            newTail = newTail->next;
        }

        //breaking cycle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};