#include<bits/stdc++.h>
using namespace std;


// Using Map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode* ,int> m;
        ListNode* temp = head;
        while(temp!=NULL){
            if(m.find(temp) != m.end()) return true;
            else{
                m[temp] = 1;
            }
            temp = temp->next;
        }
        return false;
    }
};


//Using Tortoise and Hare Algo

bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }

int main(){

}