#include <stack>
#include <string>
#include <sstream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "[]";
        stack<pair<bool, TreeNode*>> s;
        s.emplace(true, root->right);
        s.emplace(true, root->left);
        stringstream ss;
        ss << "[" << root->val;
        bool first = true;
        while (!s.empty()) {
            auto [flag, p] = s.top();
            s.pop();
            if (!p) {
                ss << ",X";
                continue;
            }
            if (flag) {
                s.emplace(true, p->right);
                s.emplace(true, p->left);
                s.emplace(false, p);
            }
            else {
                ss << "," << p->val;
            }
        }
        ss << "]";
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 2)
            return nullptr;
        auto [i, root] = decode(data, 1, data.size()-1);
        return root;
    }

    pair<int, TreeNode*> decode(const string& data, int i, int j) {
        if (data[i] == 'X')
            return make_pair(i+2, nullptr);
        auto k = i;
        for (; k != j && data[k] != ','; ++k);
        auto root = new TreeNode(stoi(data.substr(i, k-i)));
        tie(k, root->left) = decode(data, k+1, j);
        tie(k, root->right) = decode(data, k, j);
        return make_pair(k, root);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));