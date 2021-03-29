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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        bool left2right = true;
        vector<vector<int>> ans; 
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);
        stack<TreeNode*> s2;
        while (!s.empty()) {
            while (!s.empty()) {
                auto p = s.top();
                s.pop();
                v.push_back(p->val);
                if (left2right) {
                    if (p->left)
                        s2.push(p->left);
                    if (p->right)
                        s2.push(p->right);
                }
                else {
                    if (p->right)
                        s2.push(p->right);
                    if (p->left)
                        s2.push(p->left);
                }
            }
            ans.push_back(std::move(v));
            v.clear();
            s = std::move(s2);
            s2 = {};
            left2right = !left2right;
        }
        return ans;
    }
};