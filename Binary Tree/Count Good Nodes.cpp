#include <algorithm> // for std::max

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root) {
        // Call the recursive function with the root and the maximum value encountered so far
        return countGoodNodes(root, root->val);
    }
    
private:
    int countGoodNodes(TreeNode* root, int maxValue) {
        // Base case: if the current node is nullptr, return 0
        if (root == nullptr) {
            return 0;
        }
        
        // Count the current node as a good node if its value is greater than or equal to the maximum value encountered so far
        int goodNodeCount = root->val >= maxValue ? 1 : 0;
        
        // Update the maximum value encountered so far for the child nodes
        maxValue = std::max(maxValue, root->val);
        
        // Recursively count the number of good nodes in the left and right subtrees
        int leftGoodNodes = countGoodNodes(root->left, maxValue);
        int rightGoodNodes = countGoodNodes(root->right, maxValue);
        
        // Return the total count of good nodes in the subtree rooted at the current node
        return goodNodeCount + leftGoodNodes + rightGoodNodes;
    }
};
