struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        int extra = 0;
        ListNode *l = nullptr, *head = nullptr;
        while (l1 || l2) {
            int v = (l1?l1->val:0) + (l2?l2->val:0) + extra;
            extra = v > 9? 1: 0;
            if (!head) {
                head = l = new ListNode(v % 10);
            }
            else {
                l->next = new ListNode(v % 10);
                l = l->next;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (extra)
            l->next = new ListNode(extra);

        return head;
    }
};