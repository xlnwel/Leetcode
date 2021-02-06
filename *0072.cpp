#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (auto i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (auto i = 1; i <= n; ++i)
            dp[0][i] = i;
        for (auto i = 1; i <= m; ++i) {
            for (auto j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
        return dp[m-1][n-1];
    }
};


/* Recursion */
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        return helper(word1, 0, word2, 0, 0);
    }
private:
    int helper(const string& s1, int beg1, const string&s2, int beg2, int n) {
        if (beg2 == s2.size())
            return n + s1.size() - beg1;
        if (beg1 == s1.size())
            return n + s2.size() - beg2;
        if (s1[beg1] == s2[beg2])
            return helper(s1, beg1+1, s2, beg2+1, n);
        ++n;
        if (s1.size() - beg1 >= s2.size() - beg2)
            return min(helper(s1, beg1+1, s2, beg2, n), helper(s1, beg1+1, s2, beg2+1, n));
        else
            return min(helper(s1, beg1, s2, beg2+1, n), helper(s1, beg1+1, s2, beg2+1, n));
    }
};