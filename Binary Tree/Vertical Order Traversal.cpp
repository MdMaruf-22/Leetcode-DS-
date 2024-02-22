#include <bits/stdc++.h>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<pair<TreeNode*, int>> q;
        map<int,vector<int>> chk;
        q.push({root,0});
        while(!q.empty()){
            int level = q.size();
            map<int,vector<int>> tmp;
            for(int i=0;i<level;i++){
                auto [node, col] = q.front();
                q.pop();
                tmp[col].push_back(node->val);
                if(node->left!=NULL) q.push({node->left,col-1});
                if(node->right!=NULL) q.push({node->right,col+1});
            }
            for(auto& [col,nodes] : tmp){
                sort(nodes.begin(),nodes.end());
                chk[col].insert(chk[col].end(),nodes.begin(),nodes.end());
            }
        }
        for (auto& [col, nodes] : chk) {
            result.push_back(nodes);
        }
        return result;
    }
};
