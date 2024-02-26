class Solution {
public:
    // Function to convert a binary tree to a string representation.
    string TreeToString(TreeNode* root) {
        // Base case: if current node is nullptr, return an empty string
        if (!root) return "";
      
        // Handle the case where the current node is a leaf node
        if (!root->left && !root->right) {
            return to_string(root->val);  // Simply return the string representation of the node value
        }
      
        // Handle the case where the current node has a left child but no right child
        if (!root->right) {
            // Return the string representation of current node value and left subtree
            return to_string(root->val) + "(" + TreeToString(root->left) + ")";
        }
      
        // If current node has both left and right children
        return to_string(root->val) + 
               "(" + TreeToString(root->left) + ")" + 
               "(" + TreeToString(root->right) + ")";
    }
};