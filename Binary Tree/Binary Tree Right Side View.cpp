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
    vector<int> rightSideView(TreeNode* root) {
       if(root == NULL) return {};
       queue<TreeNode*> q;
       q.push(root);
       vector<int> ans;
       while(!q.empty()){
           int num = q.size();
           for(int i=0;i<num;i++){
               TreeNode* node = q.front();
               q.pop();
               if(i==num-1) ans.push_back(node->val);
               if(node->left!=NULL) q.push(node->left);
               if(node->right!=NULL) q.push(node->right);
           }
       }
       return ans;
    }
};