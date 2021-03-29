#include <algorithm>

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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        auto ans = minDepth(root->left);
        if (root->right) {
            auto right = minDepth(root->right);
            ans = ans? min(ans, right): right;
        }
        return ans + 1;
    }
};
