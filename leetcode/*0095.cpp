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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int i, int j) {
        if (i > j)
            return {nullptr};
        if (i == j) {
            return {new TreeNode(i)};
        }
        vector<TreeNode*> v;
        for (auto k = i; k <= j; ++k) {
            for (auto m: helper(i, k-1)) {
                for (auto n: helper(k+1, j)) {
                    v.push_back(new TreeNode(k, m, n));
                }
            }
        }
        return v;
    }
};