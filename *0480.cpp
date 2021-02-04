#include <vector>
#include <set>

using namespace std;

class DS {
public:
    DS(int kk): k(kk) {}
    void insert(int i) {
        if (smaller.empty() || *smaller.begin() >= i)
            smaller.insert(i);
        else
            larger.insert(i);
        balance();
    }
    void erase(int i) {
        if (smaller.count(i))
            smaller.erase(smaller.find(i));
        else
            larger.erase(larger.find(i));
        balance();
    }
    double median() {
        return k & 1? *smaller.begin():(*smaller.begin() * .5 + *larger.begin() * .5);
    }
private:
    void balance() {
        if (smaller.size() > larger.size() + 1) {
            larger.insert(*smaller.begin());
            smaller.erase(smaller.begin());
        }
        else if (larger.size() > smaller.size()) {
            smaller.insert(*larger.begin());
            larger.erase(larger.begin());
        }
    }
    int k;
    multiset<int, greater<int>> smaller;
    multiset<int, less<int>> larger;
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DS ds(k);
        vector<double> ans;
        for (int i = 0; i != k; ++i)
            ds.insert(nums[i]);
        ans.push_back(ds.median());
        for (int i = k; i != nums.size(); ++i) {
            ds.insert(nums[i]);
            ds.erase(nums[i-k]);
            ans.push_back(ds.median());
        }
        return ans;
    }
};