#include<bits/stdc++.h>
using namespace std;

/*
    Using Recursion

    T.C --> O(n)
    S.C --> O(n)
*/

int helper(Node* head){
    if(temp == NULL) return 1;
    int carry = helper(head->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main(){

}