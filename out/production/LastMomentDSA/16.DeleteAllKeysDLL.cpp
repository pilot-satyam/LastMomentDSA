#include<bits/stdc++.h>
using namespace std;

Node* deleteAllOccurences(Node* head, int k){
    Node* temp = head;
    while(temp){
        if(temp->data == k){
            if(temp == head){
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if(nextNode!=NULL) nextNode->prev = prevNode;
            if(prevNode!=NULL) prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){

}