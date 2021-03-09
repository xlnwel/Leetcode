struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head{};
        auto p = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        while (l1) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while (l2) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        return head.next;
    }
};
