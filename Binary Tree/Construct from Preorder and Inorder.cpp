#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the indices of values in the inorder traversal
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }
        
        // Construct the binary tree recursively
        return buildTreeRecursive(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, indexMap);
    }
    
private:
    TreeNode* buildTreeRecursive(vector<int>& preorder, int preStart, int preEnd,
                                  vector<int>& inorder, int inStart, int inEnd,
                                  unordered_map<int, int>& indexMap) {
        // Base case: if the start index exceeds the end index in either preorder or inorder traversal, return nullptr
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        // Create a new node with the value at the current preorder start index
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        // Find the index of the root value in the inorder traversal using the indexMap
        int rootIndexInorder = indexMap[root->val];
        
        // Calculate the number of nodes in the left subtree
        int leftSubtreeSize = rootIndexInorder - inStart;
        
        // Recursively build the left and right subtrees
        root->left = buildTreeRecursive(preorder, preStart + 1, preStart + leftSubtreeSize,
                                        inorder, inStart, rootIndexInorder - 1, indexMap);
        root->right = buildTreeRecursive(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                         inorder, rootIndexInorder + 1, inEnd, indexMap);
        
        return root;
    }
};
