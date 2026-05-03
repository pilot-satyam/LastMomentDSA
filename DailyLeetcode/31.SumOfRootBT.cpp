# Intuition:
# Each root-to-leaf path in the binary tree represents a binary number, where each node's value is a bit (0 or 1). The task is to find the sum of all such binary numbers represented by all root-to-leaf paths.
#
# Approach:
# - Use DFS (Depth-First Search) to traverse the tree from root to all leaves.
# - At each node, build the current binary number by shifting the previous value left by 1 (equivalent to multiplying by 2) and adding the current node's value.
# - When a leaf node is reached, return the current binary number.
# - Sum up the values returned from all root-to-leaf paths.


/**
 * 
 * No, we use current = current << 1 | root->val specifically when we want to build a binary number from a sequence of bits (like in this problem, where each node's value is a bit). This operation shifts the current number left by one (making space for a new bit) and then adds the current node's value as the least significant bit.

In general, you use this pattern when:

You are constructing a binary number from a sequence of bits (e.g., traversing a binary tree where each node represents a bit).
You want to efficiently append a bit to the right of a binary number.
For other types of number construction (like decimal), you would use a different formula, such as current = current * 10 + digit.

So, this approach is specific to binary number construction from bits.
 * 
 */

#include<bitstd++.h>
using namespace std;

//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=daily-question&envId=2026-02-19

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    int solve(TreeNode* root, int current){
        if(root == NULL) return 0;
        //building binary number
        current = current << 1 | root->val;
        if(root->left == NULL and root->right == NULL) return current;
        return solve(root->left,current) + solve(root->right, current);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        //current is NOT the node value.
        // It represents:
        // The binary number formed from the root down to the parent of the current node.
        // “Before starting at the root, we have formed no bits yet.”
        return solve(root,0);
    }
};

int main(){

}