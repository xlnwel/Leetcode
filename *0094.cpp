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
        stack<pair<bool, TreeNode*>> s;
        vector<int> v;
        s.push({true, root});
        while (!s.empty()) {
            auto [to_search, root] = s.top();
            s.pop();
            if (!root)
                continue;
            if (to_search) {
                s.push({true, root->right});
                s.push({false, root});
                s.push({true, root->left});
            }
            else
                v.push_back(root->val);
        }
        return v;
    }
};