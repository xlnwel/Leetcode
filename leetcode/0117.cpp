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
        auto p = root;  // p points to node with at least one child
        auto next_p = root; // next_p points to the first child of p
        while (p && (p->left || p->right)) {
            next_p = p->left? p->left: p->right;
            auto p2 = next_p;
            if (p->left && p->right) {
                p2->next = p->right;
                p2 = p2->next;
            }
            for (p = p->next; p; p = p->next) {
                if (p->left) {
                    p2->next = p->left;
                    p2 = p2->next; 
                }
                if (p->right) {
                    p2->next = p->right;
                    p2 = p2->next;
                }
            }
            p = next_p;
            while (p && !p->left && !p->right) {
                p = p->next;
            }
        }
        return root;
    }
};