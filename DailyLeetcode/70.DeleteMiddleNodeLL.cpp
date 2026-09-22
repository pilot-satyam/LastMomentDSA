// Q : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/?envType=daily-question&envId=2026-06-15

#include<bitstd/stdc++.h>
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete(slow);
        return head;
    }
};

int main(){
    Solution sol;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* result1 = sol.deleteMiddle(head1);
    while (result1) {
        cout << result1->val << " ";
        result1 = result1->next;
    }
    cout << endl; // Expected output: 1 2 4 5

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    ListNode* result2 = sol.deleteMiddle(head2);
    while (result2) {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    cout << endl; // Expected output: 1 3 4

     return 0;
}