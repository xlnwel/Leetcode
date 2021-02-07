#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin()+k, 0);
        int max_sum = sum;
        for (auto i = k; i != nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};