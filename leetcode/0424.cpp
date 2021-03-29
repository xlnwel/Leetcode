#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int n = 0;
        while (i != s.size()) {
            ++freq[s[i] - 'A'];
            n = max(n, freq[s[i] - 'A']);
            if (i - j >= n + k)
                --freq[s[j++] - 'A'];
            ++i;
        }
        return min(static_cast<int>(s.size()), n + k);
    }
};