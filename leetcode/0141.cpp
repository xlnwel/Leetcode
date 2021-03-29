struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        auto p1 = head->next, p2 = head;
        while (p1 && p1->next && p1 != p2) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return p1 == p2;
    }
};