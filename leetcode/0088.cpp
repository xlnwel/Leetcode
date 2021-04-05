#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        auto k = nums1.size()-1;
        while (n >= 0) {
            nums1[k--] = (m >= 0 && nums1[m] > nums2[n])? nums1[m--]: nums2[n--];
        }
    }
};
