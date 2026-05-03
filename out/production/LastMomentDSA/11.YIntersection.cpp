#include<bits/stdc++.h>
using namespace std;

//Earlier Code 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//                  if(headA == NULL or headB == NULL)
//             return NULL;   
//          ListNode* a = headA;
//          ListNode* b = headB;

//          while(a!=b)
//          {
//             a = (a == NULL) ? headB : a->next;
//             b = (b == NULL) ? headA : b->next;
//          }   
//          return a;
    unordered_map<ListNode*,bool> m;
    ListNode* a = headA;
    ListNode* b = headB;
    while(a!=NULL)
    {
        m[a] = true;
        a = a->next;
    }
    while(b!=NULL)
    {
        if(m[b] == true)
        return b;
        b = b->next;
    }
    return NULL;
    }
};

int main(){

}