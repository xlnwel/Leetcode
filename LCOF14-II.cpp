class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;
        int q = n / 3;
        int r = n % 3;
        if (r == 1 && q != 0) {
            r = 4;
            --q;
        }
        else if (r == 0)
            r = 1;
        long ans = r;
        long mod = (1e9+7);
        for (auto i = 0; i != q; ++i)
            ans = ans * 3 % mod;
        return ans;
    }
};