#include <unordered_map>
#include <stack>

using namespace std;

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

/* Optimized version of Solution 2, in which we store m[p] in p->val after updating the answer */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        stack<pair<bool, TreeNode*>> s;
        s.push({true, root});
        int ans = root->val;
        while (!s.empty()) {
            auto [flag, p] = s.top();
            s.pop();
            if (!p)
                continue;
            if (flag) {
                s.push({false, p});
                s.push({true, p->right});
                s.push({true, p->left});
            }
            else {
                auto left = p->left?p->left->val:0;
                auto right = p->right?p->right->val:0;
                ans = max(p->val + left + right, ans);
                p->val = max(0, p->val + max(left, right));
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        unordered_map<TreeNode*, int> m;   // store <TreeNode*, max_path>, where max_path is defined as the maximum path sum in a subtree, starting from the current TreeNode
        m[nullptr] = 0;
        // run postorder search and store <val, max_path> to m
        // the maximum path can thus be find in max(p->val+p->left.max_path+p->right.max_path)
        stack<pair<bool, TreeNode*>> s;
        s.push({true, root});
        int ans = root->val;
        while (!s.empty()) {
            auto [flag, p] = s.top();
            s.pop();
            if (!p)
                continue;
            if (flag) {
                s.push({false, p});
                s.push({true, p->right});
                s.push({true, p->left});
            }
            else {
                m[p] = max(0, p->val + max(m[p->left], m[p->right]));
                ans = max(p->val + m[p->left] + m[p->right], ans);
            }
        }
        return ans;
    }
};