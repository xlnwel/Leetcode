#include <limits>

using namespace std;

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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        auto left = numeric_limits<long long>::min();
        auto right = numeric_limits<long long>::max();
        return helper(root, left, right);
    }
private:
    bool helper(TreeNode* p, long long left, long long right) {
        if (p->val <= left || p->val >= right)
            return false;
        return (!(p->left) || helper(p->left, left, min(right, static_cast<long long>(p->val))))
            && (!(p->right) || helper(p->right, max(left, static_cast<long long>(p->val)), right));
    }
};