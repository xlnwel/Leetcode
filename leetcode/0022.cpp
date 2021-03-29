#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s(n*2, ' ');
        helper(s, 0, n, 0);
        return ans;
    }
private:
    void helper(string& s, int i, int n, int left) {
        if (n > 0) {
            s[i] = '(';
            if (i == s.size() - 1)
                ans.push_back(s);
            else
                helper(s, i+1, n-1, left+1);
        }
        if (left > 0) {
            s[i] = ')';
            if (i == s.size() - 1)
                ans.push_back(s);
            else
                helper(s, i+1, n, left-1);
        }
    }
    vector<string> ans;
};