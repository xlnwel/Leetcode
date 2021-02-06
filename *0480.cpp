#include <vector>
#include <set>

using namespace std;

class DS {
public:
    DS() {}
    void insert(int x) {
        x > *bot.begin()? top.insert(x): bot.insert(x);
        balance();
    }
    void remove(int x) {
        if (auto itr = bot.find(x); itr != bot.end()) {
            assert(bot.count(x));
            bot.erase(itr);
        }
        else {
            assert(top.count(x));
            top.erase(top.find(x));
        }
        balance();
    }
    double median() {
        return bot.size() == top.size()? *bot.begin() * .5 + *top.begin() * .5: *bot.begin();
    }
private:
    void balance() {
        if (top.size() > bot.size()) {
            bot.insert(*top.begin());
            top.erase(top.begin());
        }
        else if (top.size() + 1 < bot.size()) {
            top.insert(*bot.begin());
            bot.erase(bot.begin());
        }
    }
    multiset<int> top;
    multiset<int, greater<int>> bot;

};


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DS ds;
        vector<double> ans;
        for (auto i = 0; i != k; ++i)
            ds.insert(nums[i]);
        ans.push_back(ds.median());
        for (auto i = k, j = 0; i != nums.size(); ++i) {
            ds.insert(nums[i]);
            ds.remove(nums[j++]);
            ans.push_back(ds.median());
        }
        return ans;
    }
};