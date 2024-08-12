#include<bits/stdc++.h>
using namespace std;

/*
Q: https://leetcode.com/problems/binary-search-tree-iterator/
*/

/*
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class BSTIterator {

private: stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushAllNodes(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAllNodes(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAllNodes(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
};

/*
    T.C ===> O(1)ForNext()AndHasnext(),O(N)ForConstructor*/

/***
 * THEORY
 */

/*
Why Do We Use a Stack in BSTIterator?
Key Idea: We use a stack to help us efficiently traverse a Binary Search Tree (BST) in ascending order
without using recursion.

Simple Explanation:
Simulating Recursion:

In an in-order traversal (which visits nodes in ascending order), we would typically use recursion.
Instead of using the system's call stack (which recursion does), we use our own stack to keep track 
of where we are in the traversal.Handling Left Subtrees:

The stack helps us process all the left children first, ensuring that we always get the smallest available element.
When we push all left children of a node onto the stack, the top of the stack always contains the next smallest element.
Maintaining State:

The stack keeps track of the nodes that we need to visit next.
This allows us to "pause" the traversal and "resume" it exactly where we left off.
Step-by-Step Process:
Initialization:

When we create the iterator, we push all left descendants of the root onto the stack.
This setup ensures the smallest element is on top.
Next Smallest Element:

*** When we call next(), we pop the top element from the stack, which is the next smallest element.
Then, we push all left descendants of the popped node's right child onto the stack to ensure the next smallest element is ready for the next call.
Checking for More Elements:

The hasNext() function simply checks if the stack is not empty, indicating there are more elements to visit.
*/


//Summary: 
/*
Why a stack? To keep track of where we are in the tree without using recursion.
What does it do? It ensures that we always know the next smallest element by maintaining the state of our traversal.
Result: Efficiently iterate through the BST in ascending order.*/


int main(){

}