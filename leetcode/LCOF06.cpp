#include <vector>
#include <deque>

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
    vector<int> reversePrint(ListNode* head) {
        deque<int> ans;
        while (head) {
            ans.push_front(head->val);
            head = head->next;
        }
        return vector(ans.begin(), ans.end());
    }
};