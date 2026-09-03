class Solution {
public:
    struct Node {
        int val;
        Node *left, *right;

        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(int value) : val(value), left(nullptr), right(nullptr) {}
    };

    int calc(Node* root, int n, int k) {
        if (n == 1) return root->val;
        int mid = 1 << (n-2);
        if (k <= mid) {
            if (!root->left) root->left = new Node(root->val == 0 ? 0 : 1);
            return calc(root->left, n - 1, k);
        } else {
            if (!root->right) root->right = new Node(root->val == 0 ? 1 : 0);
            return calc(root->right, n - 1, k - mid);
        }
    }
    int kthGrammar(int n, int k) {
        Node* root = new Node(0); 
        return calc(root, n, k);
        delete root;
    }
};