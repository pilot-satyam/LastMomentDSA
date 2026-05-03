#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    Node* findTail(Node* head){
        Node* temp = head;
        while(temp) temp = temp->next;
        return temp;
    }

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        if(head == NULL) return ans;
        Node* left = head;
        Node* right = findTail(head);
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data,right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data > target){
                right = right->prev;
            }
            else{
                left = left->next;
            }
        }
    }
};

int main(){

}