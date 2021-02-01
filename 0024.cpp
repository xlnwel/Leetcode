struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode first;
        first.next = head;
        auto p = &first;
        while (p && p->next && p->next->next) {
            auto p2 = p->next;
            auto p3 = p->next->next;
            p2->next = p3->next;
            p3->next = p2;
            p->next = p3;
            p = p2;
        }
        return first.next;
    }
};