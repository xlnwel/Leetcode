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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    TreeNode* helper(vector<int>::iterator b1, vector<int>::iterator e1,
        vector<int>::iterator b2, vector<int>::iterator e2) {
        if (b1 == e1)
            return nullptr;
        // assert(distance(b1, e1) == distance(b2, e2));
        auto root = new TreeNode(*b1);
        auto mi1 = b1;
        auto mi2 = b2;
        for (; mi1 != e1 && mi2 != e2 && *mi2 != *b1; ++mi1, ++mi2) {}
        root->left = helper(b1+1, mi1+1, b2, mi2);
        root->right = helper(mi1+1, e1, mi2+1, e2);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        stack<TreeNode*> s;
        auto root = new TreeNode(preorder[0]);
        s.push(root);
        int k = 0;
        for (auto i = 1; i != preorder.size(); ++i) {
            auto p = s.top();
            if (p->val != inorder[k]) {
                p->left = new TreeNode(preorder[i]);
                s.push(p->left);
            }
            else {
                while (!s.empty() && s.top()->val == inorder[k]) {
                    p = s.top();
                    s.pop();
                    ++k;
                }
                p->right = new TreeNode(preorder[i]);
                s.push(p->right);
            }
        }
        return root;
    }
};
