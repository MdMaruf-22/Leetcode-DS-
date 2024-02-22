#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent; // For this example, assuming nodes have parent pointers
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};
class Solution {
public:
    TreeNode* run(TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, int> dprev;
        TreeNode* pi = parseSingle(p, dprev);
        TreeNode* qi = parseSingle(q, dprev);
        return qi;
    }

    TreeNode* parseSingle(TreeNode* root, unordered_map<TreeNode*, int>& dprev) {
        if(root==NULL) return NULL;
        if(dprev.find(root)!=dprev.end()) return root; //LCA FOUND
        dprev[root]=1;
        TreeNode* node =  parseSingle(root->parent, dprev);
        return node;
    }
};