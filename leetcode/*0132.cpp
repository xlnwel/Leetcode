#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minCut(string s) {
        // compute palindrome for each substring
        vector pdp(s.size(), vector(s.size(), false));
        for (auto i = 1; i != s.size(); ++i) {
            pdp[i][i] = true;
            for (auto l = 1; i-l >= 0 && i+l-1 < s.size() && s[i-l] == s[i+l-1]; ++l) {
                pdp[i-l][i+l-1] = true;
            }
            for (auto l = 1; i-l >= 0 && i+l < s.size() && s[i-l] == s[i+l]; ++l)
                pdp[i-l][i+l] = true;
        }
        // find the minimum number of partition
        vector dp(s.size(), s.size()-1);
        for (auto l = 0; l != s.size(); ++l) {
            if (pdp[0][l])
                dp[l] = 0;
            else {
                for (auto i = 1; i <= l; ++i) {
                    if (pdp[i][l] && dp[i-1] + 1 < dp[l]) {
                        dp[l] = dp[i-1] + 1;
                    }
                }
            }
        }
        return dp.back();
    }
};


class Solution1 {
public:
    int minCut(string s) {
        vector dp(s.size(), s.size());
        dp[0] = 1;
        for (auto i = 1; i != s.size(); ++i) {
            if (isPalindrome(s, 0, i)) {
                dp[i] = 1;
                continue;
            }
            for (auto j = 1; j <= i; ++j) {
                if (isPalindrome(s, j, i))
                    dp[i] = min(dp[i], dp[j-1]+1);
            }
        }
        return dp.back()-1;
    }
private:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};


class Solution2 {
public:
    int minCut(string s) {
        ans = s.size();
        helper(s, 0, 0);
        return ans;
    }
private:
    void helper(const string& s, int i, int n) {
        if (n > ans)
            return;
        if (i == s.size())
            ans = min(n-1, ans);
        for (int k = s.size()-1; k >= i; --k) {
            if (is_palindrome(s, i, k)) {
                helper(s, k+1, n+1);
            }
        }
    }
    bool is_palindrome(const string& s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    int ans;
};