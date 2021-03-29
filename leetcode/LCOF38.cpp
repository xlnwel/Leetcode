#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        backtrack(s, 0);
        return ans;
    }
private:
    void backtrack(string& s, int n) {
        if (n == s.size()) {
            ans.push_back(s);
            return;
        }
        
        for (auto i = n; i != s.size(); ++i) {
            auto flag = true;
            for (auto j = n; j != i; ++j)
                if (s[i] == s[j])
                    flag = false;
            if (flag) {
                swap(s[i], s[n]);
                backtrack(s, n+1);
                swap(s[i], s[n]);
            }
        }
    }
    vector<string> ans;
};

class Solution2 {
public:
    vector<string> permutation(string s) {
        backtrack(s, 0);
        return ans;
    }
private:
    void backtrack(string& s, int n) {
        if (n == s.size()) {
            ans.push_back(s);
            return;
        }
        unordered_set<char> cs;
        for (auto i = n; i != s.size(); ++i) {
            if (cs.find(s[i]) == cs.end()) {
                cs.insert(s[i]);
                swap(s[i], s[n]);
                backtrack(s, n+1);
                swap(s[i], s[n]);
            }
        }
    }
    vector<string> ans;
};