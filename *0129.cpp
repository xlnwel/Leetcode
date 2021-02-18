class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right, TreeNode* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
private:
    int helper(TreeNode* p, int sum) {
        if (!p)
            return 0;
        sum = 10 * sum + p->val;
        if (!p->left && !p->right) 
            return sum;
        return helper(p->left, sum) + helper(p->right, sum);
    }
};
