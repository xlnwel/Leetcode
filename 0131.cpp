#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        is_palindrom = vector(s.size(), vector(s.size(), false));
        for (auto i = 0; i != s.size(); ++i) {
            for (auto l = 0; i - l >= 0 && i + l < s.size() && s[i-l] == s[i+l]; ++l) {
                is_palindrom[i-l][i+l] = true;
            }
            for (auto l = 0; i - l >= 0 && i + l + 1 < s.size() && s[i-l] == s[i+l+1]; ++l)
                is_palindrom[i-l][i+l+1] = true;
        }
        helper(s, 0);
        return ans;
    }
private:
    void helper(const string& s, int i) {
        if (i == s.size()) {
            ans.push_back(v);
            return;
        }
        for (auto k = i; k != s.size(); ++k) {
            if (is_palindrom[i][k]) {
                v.push_back(s.substr(i, k-i+1));
                helper(s, k+1);
                v.pop_back();
            }
        }
    }
    vector<string> v;
    vector<vector<string>> ans;
    vector<vector<bool>> is_palindrom;
};

class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        helper(s, s.begin());
        return ans;
    }
private:
    void helper(const string& s, string::iterator beg) {
        if (beg == s.end()) {
            ans.push_back(v);
            return;
        }
        for (auto itr = beg; itr != s.end(); ++itr) {
            if (is_palindrom(beg, itr)) {
                v.push_back(string(beg, itr+1));
                helper(s, itr+1);
                v.pop_back();
            }
        }
    }
    bool is_palindrom(string::iterator beg, string::iterator end) {
        while (beg < end) {
            if (*beg++ != *end--)
                return false;
        }
        return true;
    }
    vector<string> v;
    vector<vector<string>> ans;
};