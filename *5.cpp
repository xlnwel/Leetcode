#include <string>
#include <utility>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int maxlen = 1;
        int left = 0;
        for (auto p = 0; p < s.size() - 1; ++p) {
            auto t1 = helper(s, p, p);
            auto t2 = helper(s, p, p+1);
            if (get<1>(t1) > maxlen) {
                left = get<0>(t1);
                maxlen = get<1>(t1);
            }
            if (get<1>(t2) > maxlen) {
                left = get<0>(t2);
                maxlen = get<1>(t2);
            }
        }
        return s.substr(left, maxlen);
    }
private:
    pair<int, int> helper(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        ++left;
        return make_pair(left, right-left);
    }
};
