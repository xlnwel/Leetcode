#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> s, s2;
        s.push(root);
        vector<int> ans;
        while (!s.empty()) {
            while (!s.empty()) {
                auto p = s.front();
                ans.push_back(p->val);
                s.pop();
                if (p->left)
                    s2.push(p->left);
                if (p->right)
                    s2.push(p->right);
            }
            s = std::move(s2);
            s2 = {};
        }
        return ans;
    }
};