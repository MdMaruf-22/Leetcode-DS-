class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        getSum(root,NULL,NULL,sum);
        return sum;
    }

    void getSum(TreeNode* node,TreeNode* par,TreeNode* grandpar,int& sum){
        if(node==NULL) return;
        if(grandpar!=NULL && grandpar->val%2==0){
            sum+= node->val;
        }
        getSum(node->left,node,par,sum);
        getSum(node->right,node,par,sum);
    }
};