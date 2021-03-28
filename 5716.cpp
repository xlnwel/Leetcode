#include <vector>

using namespace std;

class Solution {
public:
    int maxNiceDivisors(int n) {
        if (n < 4)
            return n;
        auto q = n / 3;
        auto r = n % 3;
        if (r == 1 && q) {
            r = 4;
            --q;
        }
        else if (r == 0) {
            r = 1;
        }
        return compute(q, r);
    }
private:
    int compute(int q, int r) {
        long ans = r;
        long mod = (1e9+7);
        vector<long> v(1, 3);
        auto x = 2;
        while (x <= q) {
            v.push_back(v.back() * v.back() % mod);
            x <<= 1;
        }
        for (int i = v.size(); i >= 0; --i) {
            if (q >= (1<<i)) {
                ans = ans * v[i] % mod;
                q -= 1<<i;
            }
        }
        return ans;
    }
};
