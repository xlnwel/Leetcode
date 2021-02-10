#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return check(s1.begin(), s1.end(), s2.begin(), s2.end());
    }
private:
    bool check(string::iterator b1, string::iterator e1, string::iterator b2, string::iterator e2) {
        if (b1 == e1 || (distance(b1, e1) == 1 && *b1 == *b2))
            return true;
        array<int, 26> v{};
        for (auto i = b1; i != e1; ++i)
            ++v[*i-'a'];
        for (auto i = b2; i != e2; ++i)
            if (--v[*i-'a'] < 0)
                return false;
        for (auto i = 1; i != distance(b1, e1); ++i) {
            if (check(b1, b1+i, b2, b2+i) && check(b1+i, e1, b2+i, e2))
                return true;
            if (check(b1, b1+i, e2-i, e2) && check(b1+i, e1, b2, e2-i))
                return true;
        }
        return false;
    }
};