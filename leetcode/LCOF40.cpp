#include <vector>

using namespace std;


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0)
            return {};
        auto x = quick_select(arr, 0, arr.size() - 1, k);
        auto ans = vector(arr.begin(), arr.begin() + k);
        return ans;
    }
private:
    int quick_select(vector<int>& v, int l, int r, int k) {
        int i = partition(v, l, r);
        if (i == k-1)
            return i;
        if (i > k-1)
            return quick_select(v, l, i-1, k);
        return quick_select(v, i+1, r, k);
    }
    int partition(vector<int>& v, int l, int r) {
        auto x = v[r];
        for (auto i = l; i != r; ++i) {
            if (v[i] < x)
                swap(v[l++], v[i]);
        }
        swap(v[l], v[r]);
        return l;
    }
};