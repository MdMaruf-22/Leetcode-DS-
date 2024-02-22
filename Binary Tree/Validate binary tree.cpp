class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial range as [LONG_MIN, LONG_MAX]
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        // Base case: if the current node is null, it's a valid BST
        if (root == nullptr) return true;
        
        // Check if the current node's value falls within the valid range
        if (root->val <= minVal || root->val >= maxVal) return false;
        
        // Recursively check the left subtree with updated maxVal
        // and right subtree with updated minVal
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};