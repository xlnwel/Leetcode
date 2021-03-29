#include <utility>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        long m = n;
        if (m < 0) {
            x = 1 / x;
            m = -m;
        }
        
        double  ans = 1;
        while (m) {
            auto [i, j] = compute(x, m);
            m = i;
            ans *= j;
        }
        return ans;
    }
private:
    pair<long, double> compute(double x, long n) {
        if (n == 1)
            return {0, x};
        long i = 1;
        while (i <= n / 2) {
            i *= 2;
            x *= x;
        }
        return {n - i, x};
    }
};
