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
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root = tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    TreeNode* tree(vector<int>& preorder,int preSt,int preEn,vector<int>& inorder,int inSt,int inEn,unordered_map<int,int> m){
        if(preSt>preEn || inSt>inEn) return NULL;
        TreeNode* root = new TreeNode(preorder[preSt]);
        int rootIndex = m[root->val];
        int left = rootIndex - inSt;
        root->left = tree(preorder,preSt+1,preSt+left,inorder,inSt,rootIndex-1,m);
        root->right = tree(preorder,preSt+left+1,preEn,inorder,rootIndex+1,inEn,m);
        return root;
    }
};
