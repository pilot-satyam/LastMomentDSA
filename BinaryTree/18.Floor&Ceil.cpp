#include<bits/stdc++.h>
using namespace std;

/*

The findCeil function finds the smallest value greater than or equal to the key by traversing the BST.
The findFloor function finds the largest value less than or equal to the key by traversing the BST.

*/
class Solution {
    int findFloor(TreeNode* root, int key) {
        int floor = -1;
        while (root) {
            if (root->val == key) {
                floor = root->val;
                return floor;
            }
            if (key > root->val) {
                floor = root->val;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
    }

    int findCeil(TreeNode* root, int key) {
        int ceil = -1;
        while (root) {
            if (root->val == key) {
                ceil = root->val;
                return ceil;
            }
            if (key > root->val) {
                root = root->right;
            } else {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        for (int node : queries) {
            int c = findCeil(root, node);
            int f = findFloor(root, node);
            ans.push_back({f, c});
        }
        return ans;
    }
};


int main(){

}