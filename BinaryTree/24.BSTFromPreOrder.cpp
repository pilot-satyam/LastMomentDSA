#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
*/

/*
Imp :   preOrder[i++] means "use the current value of i in preOrder[i] and then increment i".
        If i is 0, preOrder[i] is preOrder[0]. 
*/

/*
BASE CASE : Given the preorder list [8, 5, 1, 7, 10, 12]:

    1st BaseCase => When i reaches 6, which is equal to the size of preOrder, it means all elements
        have been used to construct the tree.

    2nd BaseCase => solve(preOrder, i = 3, boundary = 1) with 7.
        7 is greater than 1, so it cannot be placed as the left child of 1.
        The condition preOrder[i] > boundary (7 > 1) is true.
        Return NULL, meaning 1 has no left child.

        7 is less than 5, so it cannot be placed as the right child of 1.
        The condition preOrder[i] > boundary (7 > 5) is true.
        Return NULL, meaning 1 has no right child.
*/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder,i,INT_MAX);
    }

    TreeNode* solve(vector<int>& preOrder, int &i , int boundary){
        if(i == preOrder.size() || preOrder[i] > boundary) return NULL;
        TreeNode* root = new TreeNode(preOrder[i++]);
        root->left = solve(preOrder,i,root->val);
        root->right = solve(preOrder,i,boundary);
        return root;
    }
};

int main(){

}