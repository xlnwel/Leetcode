#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<bool, TreeNode*>> s;
        s.emplace(true, root);
        while (!s.empty()) {
            auto [flag, p] = s.top();
            s.pop();
            if (!p)
                continue;
            if (flag) {
                s.emplace(true, p->right);
                s.emplace(false, p);
                s.emplace(true, p->left);
            }
            else
                ans.push_back(p->val);
        }
        return ans;
    }
};