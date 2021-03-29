#include <string>
#include <array>


using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> a{};
        for (auto c: s1)
            ++a[c-'a'];
        for (auto i = 0, j = 0; i != s2.size(); ++i) {
            if (--a[s2[i] - 'a'] < 0) {
                while (a[s2[i] - 'a'] < 0)
                    ++a[s2[j++] - 'a'];
            }
            if (i - j == s1.size()-1)
                return true;
        }
        return false;
    }
};