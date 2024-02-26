class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curr_val = INT_MIN;
            int level = q.size();
            for(int i=0;i<level;i++){
                TreeNode* node = q.front();
                curr_val = max(curr_val,node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(curr_val);
        }
        return ans;
    }
};

/*
DFS APPROACH:
class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& ans) {
        if (node == nullptr) return;
        if (level >= ans.size()) ans.push_back(node->val);
        else ans[level] = max(ans[level], node->val);
        dfs(node->left, level + 1, ans);
        dfs(node->right, level + 1, ans);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

*/