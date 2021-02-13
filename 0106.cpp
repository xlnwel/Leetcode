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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder.rbegin(), postorder.rend(), inorder.rbegin(), inorder.rend());
    }
private:
    TreeNode* helper(
        vector<int>::reverse_iterator b1, vector<int>::reverse_iterator e1,
        vector<int>::reverse_iterator b2, vector<int>::reverse_iterator e2) {
        if (b1 == e1)
            return nullptr;
        if (b1 + 1 == e1)
            return new TreeNode(*b1);
        assert(distance(b1, e1) == distance(b2, e2));
        auto root = new TreeNode(*b1);
        auto mi1 = b1;
        auto mi2 = b2;
        for (; mi1 != e1 && mi2 != e2 && *mi2 != *b1; ++mi1, ++mi2) {}
        root->right = helper(b1+1, mi1+1, b2, mi2);
        root->left = helper(mi1+1, e1, mi2+1, e2);
        return root;
    }
};