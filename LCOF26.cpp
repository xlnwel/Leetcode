struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
            return false;
        return helper(A, B, true);
    }
private:
    bool helper(TreeNode* A, TreeNode* B, bool whole_tree){
        if (!B)
            return true;
        if (!A)
            return false;
        if (A->val == B->val && helper(A->left, B->left, false) 
            && helper(A->right, B->right, false))
            return true;
        if (whole_tree)
            return helper(A->left, B, true) || helper(A->right, B, true);
        return false;
    }
};