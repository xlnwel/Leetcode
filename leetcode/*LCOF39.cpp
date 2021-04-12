#include <vector>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v = 0;
        int x = 0;
        for (auto i = 0; i != nums.size(); ++i) {
            if (v == 0)
                x = nums[i];
            v += nums[i] == x ? 1: -1;
        }
        return x;
    }
};


class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        return quick_find(nums, 0, n-1, (n+1)/2);
    }
    int quick_find(vector<int>&nums, int l, int r, int m) {
        auto p = partition(nums, l, r);
        if (p-l < m-1) {
            return quick_find(nums, p+1, r, m-p+l-1);
        }
        else if (p-l > m-1) {
            return quick_find(nums, l, p-1, m);
        }
        else {
            return nums[p];
        }
    }
    int partition(vector<int>&nums, int l, int r) {
        int x = nums[r];
        for (auto i = l; i != r; ++i) {
            if (nums[i] < x)
                swap(nums[i], nums[l++]);
        }
        swap(nums[r], nums[l]);
        return l;
    }
};