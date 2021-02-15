#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = 0;
        int m = 0;
        for (auto x: nums) {
            m = x? m+1: 0;
            n = max(m, n);
        }
        return n;
    }
};