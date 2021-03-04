#include <string>
#include <array>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size()+1 <= k)
            return s.size();
        array<int, 26> count{};
        int n = 0;
        int ans = k;
        for (auto i = 0, j = 0; i != s.size(); ++i) {
            n = max(n, ++count[s[i] - 'A']);
            if (n + k < i - j + 1)
                --count[s[j++] - 'A'];
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
