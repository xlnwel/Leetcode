#include <stack>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        stack<TreeNode*> s, s2;
        s.push(root);
        vector<vector<int>> ans;
        bool flag = true;
        while (!s.empty()) {
            vector<int> v;
            while (!s.empty()) {
                auto p = s.top();
                v.push_back(p->val);
                s.pop();
                if (auto p2 = flag? p->left: p->right)
                    s2.push(p2);
                if (auto p2 = flag? p->right: p->left)
                    s2.push(p2);
            }
            ans.push_back(std::move(v));
            s = std::move(s2);
            flag = !flag;
            s2 = {};
        }
        return ans;
    }
};