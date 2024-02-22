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
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<int, vector<int>> dic;
        deepestChildLevel(root, dic);
        
        vector<vector<int>> res;
        for (int i = 1; i <= dic.size(); ++i) {
            res.push_back(dic[i]);
        }
        
        return res;
    }

private:
    int deepestChildLevel(TreeNode* root, unordered_map<int, vector<int>>& dic) {
        if (!root) return 0;
        
        int h_left = deepestChildLevel(root->left, dic);
        int h_right = deepestChildLevel(root->right, dic);
        
        int h_level = max(h_left, h_right) + 1;
        dic[h_level].push_back(root->val);
        
        return h_level;
    }
};
/*
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent_dict;

    bool getParentNode(TreeNode* root, TreeNode* node) {
        if (root == nullptr) return false;
        if (root == node) return true; // Found a parent of node

        bool left = getParentNode(root->left, node);
        bool right = (!left) ? getParentNode(root->right, node) : false;

        // if node is found left or right --> root is parent.
        if (left || right) {
            parent_dict[node] = root;
            return true;
        }

        return false;
    }
};
*/

/*


*/