#include <stack>
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

class BSTIterator {
public:
    BSTIterator(TreeNode* root): v{} {
        if (!root)
            return;
        stack<pair<bool, TreeNode*>> s;
        s.emplace(true, root);
        while (!s.empty()) {
            auto [to_search, p] = s.top();
            s.pop();
            if (!p)
                continue;
            if (to_search) {
                s.emplace(true, p->right);
                s.emplace(false, p);
                s.emplace(true, p->left);
            }
            else {
                v.push_back(p->val);
            }
        }
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i != v.size();
    }
private:
    vector<int> v;
    int i = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */