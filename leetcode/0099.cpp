#include <limits>
#include <stack>
#include <utility>

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
    void recoverTree(TreeNode* root) {
        TreeNode *pp, *first = nullptr, *second = nullptr;
        int v = numeric_limits<int>::min();
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
            else {
                if (p->val < v) {
                    if (!first) {
                        first = pp;
                        second = p; // in case two consecutive nodes were swapped
                    }
                    else {
                        second = p;
                        break;
                    }
                }
                v = p->val;
                pp = p;
            }
        }
        swap(first->val, second->val);
    }
};