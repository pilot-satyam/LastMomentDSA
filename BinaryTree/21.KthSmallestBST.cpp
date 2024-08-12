#include<bits/stdc++.h>
using namespace std;

/*
Fundamental things: 

1) Doing inorder traversal will give you a ---> SORTED ARRAY

2) INORDER = Left Node Right --> this means u traverse left and then whenever you visit "NODE" it means
it is the point where traversal happens. 

*/

class Solution {
public:
    int ans = 0;
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
    
    void inorder(TreeNode* root,int k)
    {
        if(root == NULL) return;
        inorder(root->left,k);
        cnt++;
        if(cnt == k)
        {
            ans = root->val; //since traversal happens at node as defined above hence storing ans as root value
            return;
        }
        inorder(root->right,k);
    }
};

int main(){

}