struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode pre_node(0, head);
        auto p0=&pre_node, p = head;
        int i = 1;
        while (i != left) {
            p0 = p;
            p = p->next;
            ++i;
        }
        auto p2 = p;
        while (i++ != right) {
            p0->next = p2->next;
            p2->next = p2->next->next;
            p0->next->next = p;
            p = p0->next;
        }
        return pre_node.next;
    }
};
