struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* prevp = nullptr;
        auto p = head, nextp = head->next;
        while (p) {
            p->next = prevp;
            prevp = p;
            p = nextp;
            if (p)
                nextp = p->next;
        }
        return prevp;
    }
};