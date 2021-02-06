#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = 0;
        int cost = 0;
        for (int i = 0, j = 0; i != s.size(); ++i) {
            cost += abs(s[i] - t[i]);
            while (cost > maxCost) {
                cost -= abs(s[j] - t[j]);
                ++j;
            }
            n = max(n, i - j + 1);
        }
        return n;
    }
};