#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        string s(digits.size(), ' ');
        helper(digits, s, 0);
        return ans;
    }
private:
    void helper(const string& d, string& s, int i) {
        for (auto c: m[d[i]]) {
            s[i] = c;
            if (i == d.size() - 1)
                ans.push_back(s);
            else
                helper(d, s, i+1);
        }
    }
    vector<string> ans;
    map<char, string> m;
};