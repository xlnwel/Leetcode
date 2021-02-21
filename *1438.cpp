#include <vector>
#include <deque>
#include <set>
#include <utility>

using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_dq, min_dq;
        max_dq.push_back(nums[0]);
        min_dq.push_back(nums[0]);
        int n = 1, ans = 0;
        for (auto i = 1, j = 0; i != nums.size(); ++i) {
            while (!max_dq.empty() && max_dq.back() < nums[i])
                max_dq.pop_back();
            while (!min_dq.empty() && min_dq.back() > nums[i])
                min_dq.pop_back();
            max_dq.push_back(nums[i]);
            min_dq.push_back(nums[i]);
            while (max_dq.front() - min_dq.front() > limit) {
                if (nums[j] == max_dq.front())
                    max_dq.pop_front();
                if (nums[j] == min_dq.front())
                    min_dq.pop_front();
                ++j;
            }
            n = max(n, i - j + 1);
        }
        return n;
    }
};

class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = 1;
        for (auto i = 0, j = 0; i != nums.size(); ++i) {
            assert(s.size() == i - j);
            s.insert(nums[i]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[j++]));
            }
            n = max(n, i-j+1);
        }
        return n;
    }
};


class Solution3 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        auto less = [](pair<int, int> x, pair<int, int> y) {
            return x.first < y.first || x.second < y.second;
        };
        auto greater = [](pair<int, int> x, pair<int, int> y) {
            return x.first > y.first || x.second < y.second;
        };
        set<pair<int, int>, decltype(less)> min_q(less);
        set<pair<int, int>, decltype(greater)> max_q(greater);
        int n = 1;
        pair<int, int> min_val;
        pair<int, int> max_val;
        for (auto i = 0, j = 0; i != nums.size(); ++i) {
            assert(min_q.size() == i - j);
            min_q.emplace(nums[i], i);
            max_q.emplace(nums[i], i);
            while (max_val = *max_q.begin(), min_val = *min_q.begin(), 
                    max_val.first - min_val.first > limit) {
                min_q.erase({nums[j], j});
                max_q.erase({nums[j], j});
                ++j;
            }
            n = max(n, i-j+1);
        }
        return n;
    }
};


class Solution3 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        vector dp(nums.size(), vector(nums.size(), 0));
        int n = 1;
        for (auto i = 0; i != nums.size(); ++i) {
            auto min_j = i, max_j = i;
            dp[i][i] = 1;
            for (auto j = i+1; j != nums.size(); ++j) {
                if (nums[j] > nums[max_j])
                    max_j = j;
                else if (nums[j] < nums[min_j])
                    min_j = j;
                dp[i][j] = nums[max_j] - nums[min_j];
                if (dp[i][j] > limit)
                    break;
                else if (n < j - i + 1)
                    n = j-i+1;
            }
        }
        return n;
    }
};