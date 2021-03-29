struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode dummy(head->val-1, head);
        auto p1 = &dummy, p2 = head;
        while (p2) {
            auto skip = false;
            while (p2 && p1->val == p2->val) {
                p2 = p2->next;
                p1->next = p2;
                skip = true;
            }
            if (!skip) {
                p1 = p2;
                p2 = p2->next;
            }
        }
        return dummy.next;
    }
};
