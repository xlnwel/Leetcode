#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* x, ListNode* y) {
            return x->val > y->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        for (auto p: lists) {
            if (p)
                pq.push(p);
        }
        ListNode head;
        auto p = &head;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            p->next = node;
            p = p->next;
            if (node->next)
                pq.push(node->next);
        }
        return head.next;
    }
};


/* Divide and conquer */
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists.begin(), lists.end());
    }
private:
    ListNode* merge(vector<ListNode*>::iterator beg, vector<ListNode*>::iterator end) {
        int n = end - beg;
        if (n == 0)
            return nullptr;
        if (n == 1)
            return *beg;
        if (n == 2)
            return merge(*beg, *(beg+1));
        auto l1 = merge(beg, beg + n/2);
        auto l2 = merge(beg + n/2, end);
        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode head;
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
        
        if (l1) 
            p->next = l1;
        if (l2) 
            p->next = l2;
            
        return head.next;
    }
};
