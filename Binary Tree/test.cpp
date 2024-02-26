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