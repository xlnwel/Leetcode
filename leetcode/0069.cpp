class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        int l=0, r=x;
        int m;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (m <= x / m) {
                l = m;
            }
            else
                r = m;
        }
        return l;
    }
};