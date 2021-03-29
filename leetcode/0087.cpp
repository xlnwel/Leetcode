#include <string>
#include <array>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1.begin(), s1.end(), s2.begin(), s2.end());
    }
private:
    bool isScramble(
        string::iterator b1, string::iterator e1,
        string::iterator b2, string::iterator e2
    ) {
        assert(distance(b1, e1) == distance(b2, e2));
        if (distance(b1, e1) == 1)
            return *b1 == *b2;
        array<int, 26> counter{};
        for (auto i = b1; i != e1; ++i)
            ++counter[*i-'a'];
        for (auto i = b2; i != e2; ++i)
            if (--counter[*i-'a'] < 0)
                return false;
        
        for (auto l = 1; l != distance(b1, e1); ++l) {
            if ((isScramble(b1, b1+l, b2, b2+l) && isScramble(b1+l, e1, b2+l, e2))
                || (isScramble(e1-l, e1, b2, b2+l) && isScramble(b1, e1-l, b2+l, e2)))
                return true;
        }
        return false;
    }
};