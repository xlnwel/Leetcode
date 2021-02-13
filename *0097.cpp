#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, 0));
        dp[0][0] = true;        
        for (auto i = 0; i != s1.size(); ++i)
            dp[i+1][0] = s1[i] == s3[i] && dp[i][0];
        for (auto j = 0; j != s2.size(); ++j)
            dp[0][j+1] = s2[j] == s3[j] && dp[0][j];
        
        for (auto i = 0; i != s1.size(); ++i) {
            for (auto j = 0; j != s2.size(); ++j) {
                dp[i+1][j+1] = (s1[i] == s3[i+j+1] && dp[i][j+1])
                    || (s2[j] == s3[i+j+1] && dp[i+1][j]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};


class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return helper(s1, 0, s2, 0, s3, 0);
    }
private:
    bool helper(const string& s1, int i, const string& s2, int j, const string& s3, int k) {
        if (i == s1.size() && j == s2.size() && k == s3.size())
            return true;
        else if (k == s3.size())
            return i == s1.size() && j == s2.size();
        else if (i == s1.size())
            return s2[j] == s3[k] && helper(s1, i, s2, j+1, s3, k+1);
        else if (j == s2.size())
            return s1[i] == s3[k] && helper(s1, i+1, s2, j, s3, k+1);

        if (s1[i] == s2[j]) {
            if (s1[i] != s3[k])
                return false;
            return helper(s1, i, s2, j+1, s3, k+1) || helper(s1, i+1, s2, j, s3, k+1);
        }
        else if (s1[i] == s3[k])
            return helper(s1, i+1, s2, j, s3, k+1);
        else if (s2[j] == s3[k])
            return helper(s1, i, s2, j+1, s3, k+1);
        else
            return false;
    }
};