#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
private:
    ListNode* merge_sort(ListNode* head) {
        if (!head || !head->next)
            return head;
        bool advance_p2 = true;
        auto p = head->next, p2 = head;
        for (; p; p = p->next) {
            if ((advance_p2 = !advance_p2))
                p2 = p2->next;
        }
        p = p2->next;
        p2->next = nullptr;
        head = merge_sort(head);
        p = merge_sort(p);
        // merge
        ListNode h;
        p2 = &h;
        while (head && p) {
            if (head->val < p->val) {
                p2->next = head;
                head = head->next;
            }
            else {
                p2->next = p;
                p = p->next;
            }
            p2 = p2->next;
        }
        while (head) {
            p2->next = head;
            head = head->next;
            p2 = p2->next;
        }
        while (p) {
            p2->next = p;
            p = p->next;
            p2 = p2->next;
        }
        return h.next;
    }
};

class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        return quick_sort(head);
    }
private:
    ListNode* quick_sort(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode h;
        auto hp = &h, pp = head;
        auto pivot = head->val; // this version times out and requires sophisticated method to find an appropriate pivot node for special cases such as an already sorted long list 
        for (auto p = head->next; p; p = p->next) {
            if (p->val < pivot) {
                hp->next = p;
                hp = hp->next;
            }
            else {
                pp->next = p;
                pp = pp->next;
            }
        }
        hp->next = nullptr;
        pp->next = nullptr;
        if (h.next) {
            h.next = quick_sort(h.next);
            for (hp = h.next; hp->next; hp = hp->next) {}
            hp->next = head;
        }
        else
            h.next = head;
        head->next = quick_sort(head->next);
        assert(head->val == pivot);
        return h.next;
    }
};