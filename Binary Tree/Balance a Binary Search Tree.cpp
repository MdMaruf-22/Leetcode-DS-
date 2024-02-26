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
    vector<int> node;
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return NULL;
        inOrder(root);
        return buildTree(0,node.size()-1);
    }
    void inOrder(TreeNode* root){
        if(root==NULL) return;
        inOrder(root->left);
        node.push_back(root->val);
        inOrder(root->right);
    }
    TreeNode* buildTree(int st,int end){
        if(st>end) return NULL;
        int mid = (st+end)/2;
        TreeNode* newRoot = new TreeNode(node[mid]);
        newRoot->left = buildTree(st,mid-1);
        newRoot->right  = buildTree(mid+1,end);
        return newRoot;
    }
};