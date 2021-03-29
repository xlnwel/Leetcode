#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        vector left(height.size(), 0);
        for (auto i = 1; i != height.size()-1; ++i) {
            left[i] = max(left[i-1], height[i-1]);
        }
        vector right(height.size(), 0);
        for (auto i = height.size()-2; i > 0; --i) {
            right[i] = max(right[i+1], height[i+1]);
        }
        int waters = 0;
        for (auto i = 1; i != height.size() - 1; ++i) {
            waters += max(0, min(left[i], right[i]) - height[i]);
        }
        return waters;
    }
};