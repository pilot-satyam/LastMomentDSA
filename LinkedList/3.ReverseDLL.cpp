#include<bits/stdc++.h>
using namespace std;

Node* ReverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL; 
    Node* current = head;
    while(current!=NULL){
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        current = current->prev;
    }
    return prev->prev;
}

int main(){

}