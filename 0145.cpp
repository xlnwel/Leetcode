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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<bool, TreeNode*>> s;
        s.emplace(true, root);
        vector<int> ans;
        while (!s.empty()) {
            auto [flag, p] = s.top();
            s.pop();
            if (!p)
                continue;
            if (flag) {
                s.emplace(false, p);
                s.emplace(true, p->right);
                s.emplace(true, p->left);
            }
            else
                ans.push_back(p->val);
        }
        return ans;
    }
};