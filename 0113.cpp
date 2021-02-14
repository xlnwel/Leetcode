#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum);
        return ans;
    }
private:
    void helper(TreeNode* p, int s) {
        if (!p)
            return;
        if (!p->left && !p->right) {
            if (p->val == s) {
                v.push_back(p->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(p->val);
        if (p->left) {
            helper(p->left, s-p->val);
        }
        if (p->right) {
            helper(p->right, s-p->val);
        }
        v.pop_back();
    }
    vector<int> v;
    vector<vector<int>> ans;
};