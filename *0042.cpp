#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        int n = height.size();
        vector<int> left(n), right(n);
        for (auto i = 1; i != n; ++i) {
            left[i] = max(left[i-1], height[i-1]);
        }
        for (auto i = n-2; i >= 0; --i) {
            right[i] = max(right[i+1], height[i+1]);
        }
        int water = 0;
        for (auto i = 1; i < n-1; ++i) {
            auto j = min(left[i], right[i]);
            water += max(0, j - height[i]);
        }
        return water;
    }
};