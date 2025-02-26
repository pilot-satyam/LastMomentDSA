#include<bits/stdc++.h>
using namespace std;

    /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
   class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q) return root;

        TreeNode* left =lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == NULL) return right;       
        else if(right == NULL) return left;
        else return root;
    }
};


/**
 * If given Parent pointer reference
 *  
 */
TreeNode* lca(TreeNode* n1, TreeNode* n2){
    unordered_set<TreeNode*> set;
    while(n1 != nullptr){
        set.insert(n1);
        n1 = n1->parent;
    }
    while(n2 != nullptr){
        if(set.count(n2)){
            return n2; //first common ancestor found
        }
        n2 = n2->parent;
    }
    return nullptr; //no common ancestor found
}

int main(){

}