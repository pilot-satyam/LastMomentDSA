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

/*
    In general how to use Merge Sort: 

    mergeSort(arr,low,high){
        if(low == high) return; // when there is a single element
        mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high)
    }


*/

class Solution{

    public: ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    public: ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1!=NULL and list2!=NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;
        return dummyNode->next;
    }

    public: ListNode* sortList(ListNode* head){
        if(head  == NULL || head->next == NULL) return head;
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);    
        return mergeTwoList(left,right);
    }
};

int main(){

}