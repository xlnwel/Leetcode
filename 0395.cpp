#include <string>
#include <array>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n_good = 0, n_bad = 0;
        int ans = 0;
        array<int, 26> v{};
        for (auto i = 0; i != s.size(); ++i) {
            auto idx = s[i] - 'a';
            if (++v[idx] >= k) {
                if (v[idx] == k) {
                    ++n_good;
                    n_bad = max(0, n_bad-1);
                }
                if (n_bad == 0) {
                    ans = i+1;
                    continue;
                }
                auto m = n_good;
                auto n = n_bad;
                auto tmp = v;
                for (auto j = 0; j < i-ans; ++j) {
                    auto idx2 = s[j] - 'a';
                    if (--tmp[idx2] == k-1) {
                        --m;
                        ++n;
                    }
                    else if (tmp[idx2] == 0 && --n == 0) {
                        ans = max(ans, i - j);
                    }
                }
            }
            else if (v[idx] == 1) {
                ++n_bad;
            }
        }
        return ans;
    }
};
