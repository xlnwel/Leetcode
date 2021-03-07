#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty())
            return {};
        stack<int> s;
        int idx;
        int max_val = nums[0];
        vector ans(nums.size(), -1);
        for (auto i = 0; i != nums.size(); ++i) {
            while (!s.empty() && nums[idx = s.top()] < nums[i]) {
                s.pop();
                ans[idx] = nums[i];
            }
            s.push(i);
            if (nums[i] > max_val)
                max_val = nums[i];
        }
        for (auto i = 0; i != nums.size(); ++i) {
            while (!s.empty() && nums[idx = s.top()] < nums[i]) {
                s.pop();
                ans[idx] = nums[i];
            }
            if (nums[idx] == max_val)
                break;
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty())
            return {};
        using IntPair = pair<int, int>;
        auto comp = [](IntPair x, IntPair y) {
            return x.first > y.first;
        };
        priority_queue<IntPair, vector<IntPair>, decltype(comp)> pq(comp);
        pq.emplace(nums[0], 0);
        int max_val = nums[0];
        vector ans(nums.size(), -1);
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] > max_val)
                max_val = nums[i];
            while (!pq.empty()) {
                auto [x, idx] = pq.top();
                if (x < nums[i]) {
                    ans[idx] = nums[i];
                    pq.pop();
                }
                else
                    break;
            }
            pq.emplace(nums[i], i);
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (auto [x, idx] = pq.top(); x == max_val)
                break;
            while (!pq.empty()) {
                auto [x, idx] = pq.top();
                if (x < nums[i]) {
                    ans[idx] = nums[i];
                    pq.pop();
                }
                else
                    break;
            }
        }
        return ans;
    }
};