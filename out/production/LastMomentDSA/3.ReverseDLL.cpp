#include<bits/stdc++.h>
using namespace std;

Node* ReverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL; 
    Node* current = head;
    while(current!=NULL){
        prev = current->prev; //initially intializing prev pointer 
        current->prev = current->next; //actual starts from here
        current->next = prev;
        current = current->prev; //since now next and prev are reversed to jaha cur = cur-> next tha waha cur = cur -> prev hoga
    }
    return prev->prev;
}

int main(){

}