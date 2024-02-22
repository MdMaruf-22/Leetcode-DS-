/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return chkHeight(root)!=-1;
    }
    int chkHeight(TreeNode* root){
        if(root==NULL) return 0;
        int left = chkHeight(root->left);
        int right = chkHeight(root->right);
        if(abs(left-right)>1) return -1;
        return 1+max(left,right);
    }
};