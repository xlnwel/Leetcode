struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return root;
        auto tmp = root->right;
        root->right = mirrorTree(root->left);
        root->left = mirrorTree(tmp);
        return root;
    }
};
