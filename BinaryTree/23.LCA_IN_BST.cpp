#include<bits/stdc++.h>
using namespace std;

/*
* Logic dono given nodes either left mein hone chahiye either right side mein
  and jaha ye alag alag hue i.e 1 left and 1 right then wo point of split is LCA.
*/

class Solution{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
            if(root == NULL) return NULL;
            auto curr = root->val;
            if(p->val > curr && q->val > curr) return lowestCommonAncestor(root->right,p,q);
            if(p->val < curr && q->val < curr) return lowestCommonAncestor(root->left,p,q);
            return root;
        }
};

int main(){

}