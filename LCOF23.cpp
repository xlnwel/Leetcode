struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto p = head;
        for (auto i = 0; i != k; ++i) {
            if (p)
                p = p->next;
            else
                return nullptr;
        }
        auto p2 = head;
        while (p) {
            p = p->next;
            p2 = p2->next;
        }
        return p2;
    }
};