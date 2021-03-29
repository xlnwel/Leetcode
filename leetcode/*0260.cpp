#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long mask = 0;
        for (auto n: nums)
            mask ^= n;
        mask &= -mask;
        int x = 0, y = 0;
        for (auto n: nums) {
            if (mask & n)
                x ^= n;
            else
                y ^= n;
        }
        return {x, y};
    }
};
