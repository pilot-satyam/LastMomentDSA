#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        unordered_map<ListNode*, int> m;
        ListNode* temp = head;
        while(temp){
             if(m.find(temp)!=m.end()){
            return temp;
        }
            m[temp] = 1;
            temp = temp->next;
        }
        return NULL;    
    }
};

//Using Tortoise and Hare Algo

ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }

int main(){

}