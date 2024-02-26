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
int cnt = 0;
    int goodNodes(TreeNode* root) {
        // Call the recursive function with the root and the maximum value encountered so far
        countGoodNodes(root, INT_MIN);
        return cnt;
    }
private:
    void countGoodNodes(TreeNode* root, int maxValue) {
        // Base case: if the current node is nullptr, return 0
        if (root == nullptr) {
            return;
        }
        // If the current node's value is greater than or equal to the max value seen so far,
        // increment the count of good nodes and update the max value for the path.
        if(root->val>=maxValue){
            ++cnt;
            maxValue = root->val;
        }
        // Recursively count the number of good nodes in the left and right subtrees
        countGoodNodes(root->left, maxValue);
        countGoodNodes(root->right, maxValue);
    }
};
