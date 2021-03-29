#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
            return {};
        min_len = wordDict.begin()->size();
        max_len = wordDict.begin()->size();
        for(auto itr = wordDict.begin()+1; itr != wordDict.end(); ++itr) {
            min_len = min(min_len, static_cast<int>(itr->size()));
            max_len = max(max_len, static_cast<int>(itr->size()));
        }
        dict = unordered_set(
            move_iterator(wordDict.begin()), move_iterator(wordDict.end()));
        backtrack(s, 0);
        return ans;
    }
private:
    bool backtrack(const string& s, int i) {
        if (infeasibles.count(i))
            return false;
        if (i == s.size()) {
            stringstream ss;
            for (auto i = 0; i != buf.size()-1; ++i)
                ss << buf[i] << ' ';
            ss << buf.back();
            ans.push_back(ss.str());
            return true;
        }
        bool feasible = false;
        for (auto l = min_len; i+l <= s.size() && l <= max_len; ++l) {
            auto tmp = s.substr(i, l);
            if (dict.count(tmp)) {
                buf.push_back(tmp);
                if (backtrack(s, i+l))
                    feasible = true;
                buf.pop_back();
            }
        }
        if (!feasible)
            infeasibles.insert(i);
        return feasible;
    }
    int min_len;
    int max_len;
    unordered_set<string> dict;
    vector<string> ans;
    vector<string> buf;
    unordered_set<int> infeasibles;
};


class Solution2 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty())
            return {};
        int min_len = wordDict.begin()->size();
        int max_len = wordDict.begin()->size();
        for(auto itr = wordDict.begin()+1; itr != wordDict.end(); ++itr) {
            min_len = min(min_len, static_cast<int>(itr->size()));
            max_len = max(max_len, static_cast<int>(itr->size()));
        }
        unordered_set dict(
            move_iterator(wordDict.begin()), move_iterator(wordDict.end()));
        vector dp(s.size()+1, vector<string>());
        string tmp;
        for (auto i = min_len; i <= s.size(); ++i) {
            tmp = s.substr(0, i);
            if (dict.count(tmp)) {
                dp[i].push_back(tmp);
            }
            for (auto j = max(min_len, i-max_len); j <= i-min_len; ++j) {
                tmp = s.substr(j, i-j);
                if (dict.count(tmp)) {
                    for (const auto& x: dp[j])
                        dp[i].push_back(x + " " + tmp);
                }
            }
        }
        // reverse(dp[s.size()].begin(), dp[s.size()].end());
        return dp[s.size()];
    }
};