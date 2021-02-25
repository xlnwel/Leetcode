#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto x: nums) {
            if (s.count(x))
                return x;
            s.insert(x);
        }
        return -1;
    }
};
