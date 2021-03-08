#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        size_t m = static_cast<size_t>(pow(10, n));
        vector<int> v(m-1);
        for (size_t i = 1; i != m; ++i)
            v[i-1] = i;
        return v;
    }
};