class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // Initialize the maximum path sum to the minimum possible value
        int maxSum = numeric_limits<int>::min();
        // Call the recursive helper function to find the maximum path sum
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        // Base case: if the node is nullptr, return 0
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively calculate the maximum path sum in the left and right subtrees
        int leftSum = max(0, maxPathSumHelper(node->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(node->right, maxSum));
        
        // Update the maximum path sum seen so far
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        
        // Return the maximum sum of paths that can be extended further
        return node->val + max(leftSum, rightSum);
    }
};