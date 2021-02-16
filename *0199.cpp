#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> ans;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while (!q1.empty()) {
            ans.push_back(q1.front()->val);
            while (!q1.empty()) {
                auto p = q1.front();
                q1.pop();
                if (p->right)
                    q2.push(p->right);
                if (p->left)
                    q2.push(p->left);
            }
            q1 = std::move(q2);
            q2 = {};
        }
        return ans;
    }
};