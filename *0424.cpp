#include <string>
#include <array>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int,26> count{0};
        int n = 0;
        for (int i = 0, j = 0; i != s.size(); ++i) {
            int x = s[i] - 'A';
            ++count[x];
            n = max(n, count[x]);
            if (i - j >= n + k)
                --count[s[j++] - 'A'];
        }
        return min(static_cast<int>(s.size()), n+k);
    }
};