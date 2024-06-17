#include<bits/stdc++.h>
using namespace std;

Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(list1!=NULL and list2!=NULL){
        if(list1->data < list2->data){
        res->bottom = list1;
        res = list1;
        list1 = list1->bottom;
    }
    else{
        res->bottom = list2;
        res = list2;
        list2 = list2->bottom;
    }
    res->next = nullptr;
    }
    if(list1) res->bottom = list1;
    else res->bottom = list2;
    if(dummyNode->bottom) dummyNode->bottom->next = nullptr;
    return dummyNode->bottom;
}    

Node *flatten(Node *root)
{
   if(root == NULL || root->next==NULL) return root;
   Node* mergedHead = flatten(root->next);
   return merge(root,mergedHead);
}

int main(){
    
}