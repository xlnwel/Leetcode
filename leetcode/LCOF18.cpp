struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head)
            return nullptr;
        if (head->val == val)
            return head->next;
        for (auto pp = head, p = head->next; p; pp = pp->next, p = p->next) {
            if (p->val == val) {
                pp->next = p->next;
            }
        }
        return head;
    }
};