class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    };
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto p = head, p2 = head;
        while (p) {
            auto p3 = p->next;
            p2 = p->next = new Node(p->val);
            p2->next = p3;
            p = p3;
        }
        p = head, p2 = p->next;
        while (p) {
            if (p->random) {
                p2->random = p->random->next;
            }
            p = p2->next;
            if (p)
                p2 = p->next;
        }
        p = head, p2 = p->next;
        auto ans = p2;
        while (p) {
            p->next = p2->next;
            p = p->next;
            if (!p)
                continue;
            p2->next = p->next;
            p2 = p2->next;
        }
        return ans;
    }
};