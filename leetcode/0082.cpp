struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode dummy(head->val-1, head);
        auto pre = &dummy, p = head;
        while (p && p->next) {
            auto p2 = p->next;
            auto delp = false;
            while (p2 && p->val == p2->val) {
                delp = true;
                auto p3 = p2->next;
                delete p2;
                p2 = p3;
            }
            if (delp) {
                delete p;
                pre->next = p2;
                p = p2;
            }
            else {
                pre = p;
                p = p2;
            }
        }
        return dummy.next;
    }
};