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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
private:
    bool check(TreeNode* p, TreeNode* q) {
        if (!p || !q)
            return !p && !q;
        if (p->val != q->val)
            return false;
        return check(p->left, q->left) && check(p->right, q->right);
    }
};