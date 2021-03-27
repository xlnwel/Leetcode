struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        auto p = head;
        int n = 0;
        auto circle = [&p, &n] (auto head, int k) {
            p = head;
            n = 0;
            while (p && n != k) {
                p = p->next;
                ++n;
            }
        };
        circle(head, k);
        if (n != k) {
            k %= n;
            circle(head, k);
        }
        if (!p || k == 0)
            return head;
        auto p2 = p, p3 = head, p4 = head;
        while (p) {
            p2 = p;
            p = p->next;
            p4 = p3;
            p3 = p3->next;
        }
        p2->next = head;
        p4->next = nullptr;
        return p3;
    }
};