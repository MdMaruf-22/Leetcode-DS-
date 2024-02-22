#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // Create a stack to perform iterative in-order traversal
        stack<TreeNode*> st;
        // Pointer to track the current node during traversal
        TreeNode* current = root;
        // Counter to keep track of the number of visited nodes
        int count = 0;
        
        // Loop until current node is not null or stack is not empty
        while (current != nullptr || !st.empty()) {
            // Traverse to the leftmost node of the current subtree
            while (current != nullptr) {
                // Push each node encountered onto the stack
                st.push(current);
                // Move to the left child
                current = current->left;
            }
            // Pop a node from the stack
            current = st.top();
            st.pop();
            // Increment the count as a node is visited
            count++;
            // If count is equal to k, return the value of the current node
            if (count == k) return current->val;
            // Move to the right subtree of the popped node
            current = current->right;
        }
        
        // If k is greater than the number of nodes, return -1
        return -1;
    }
};
