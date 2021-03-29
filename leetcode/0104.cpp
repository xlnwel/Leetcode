#include <stack>

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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        int ans = 0;
        while (!s1.empty()) {
            while (!s1.empty()) {
                auto p = s1.top();
                s1.pop();
                if (p->left)
                    s2.push(p->left);
                if (p->right)
                    s2.push(p->right);
            }
            ++ans;
            s1 = std::move(s2);
            s2 = {};
        }
        return ans;
    }
};