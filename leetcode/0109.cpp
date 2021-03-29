struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }
private:
    TreeNode* helper(ListNode* b, ListNode* e) {
        if (b == e)
            return nullptr;
        if (b->next == e)
            return new TreeNode(b->val);
        auto p1 = b, p2 = b;
        while (p1 != e && p1->next != e) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return new TreeNode(p2->val, helper(b, p2), helper(p2->next, e));
    }
};