#include<bits/stdc++.h>
using namespace std;

/*
 Diameter : The diameter of a binary tree is the length of the longest path between any two nodes
             in a tree. This path may or may not pass through the root.

 Length : The length of a path between two nodes is represented by the number of edges between them.
*/

/*
IMP : Height of empty tree is -1 while Diameter of empty tree is 0.
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int diameter = 0;
       height(root,diameter);
       return diameter;
    }

    int height(TreeNode* root, int &diameter){
        if(root == NULL) return 0;
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        diameter = max(diameter,lh+rh);
        return 1 + max(lh,rh);
    }
};

int main(){

}