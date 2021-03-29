#include <iostream>
#include <cmath>

int integerBreak(int n) {
    if (n < 4)
        return n-1;
    auto r = n % 3;
    auto q = n / 3;
    if (r == 1) {
        --q;
        r = 4;
    }
    else if (r == 0)
        r = 1;
    return static_cast<int>(pow(3, q) * r);
}
