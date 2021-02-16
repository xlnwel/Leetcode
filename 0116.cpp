class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        auto first = root;
        auto next_first = root;
        while (first->left) {
            next_first = first->left;
            while (first) {
                first->left->next = first->right;
                if (first->next) {
                    first->right->next = first->next->left;
                }
                first = first->next;
            }
            first = next_first;
        }
        return root;
    }
};