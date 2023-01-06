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
    vector<int> vc;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        vc.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    void preorder(TreeNode* root){
        if(root==NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            vc.push_back(root->val);
            if(root->right!=NULL) st.push(root->right);
            if(root->left!=NULL) st.push(root->left);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //Iterative one using stack;
        preorder(root);
        //DFS,which is a recursive solution;
        //dfs(root);
        return vc;
    }
};
