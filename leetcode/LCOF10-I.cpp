#include <utility>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 3)
            return n == 0? 0: 1;
        int x = 1, y = 1;
        long long mod = 1e9+7;
        for (auto i = 2; i != n; ++i) {
            x = (x + y) % mod;
            swap(x, y);
        }
        return y;
    }
};