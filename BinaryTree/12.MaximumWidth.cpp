#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;  // Handle empty tree case

        long long int maxWidth = 0;
        queue<pair<TreeNode*, long long int>> q;  // pair of node and its index
        q.push({root, 0});

        while (!q.empty()) {
            long long int size = q.size();
            long long int minIndex = q.front().second;  // Minimum index at the current level
            long long int first, last;  // Indices of first and last nodes at the current level

            for (long long int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                long long int curIndex = q.front().second - minIndex;  // Normalize to avoid overflow
                q.pop();

                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;

                if (node->left) q.push({node->left, curIndex * 2});
                if (node->right) q.push({node->right, curIndex * 2 + 1});
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return (int) maxWidth;
    }
};

int main(){

}