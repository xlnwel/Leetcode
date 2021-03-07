#include <cmath>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n-1;
        int q = n / 3;
        int r = n % 3;
        if (r == 1 && q != 0) {
            r = 4;
            --q;
        }
        else if (r == 0)
            r = 1;
        return static_cast<int>(pow(3, q)) * r;
    }
};