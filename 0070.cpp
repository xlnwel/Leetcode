class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return n;
        int n1=1, n2=1;
        int ans;
        for (int i = 1; i != n; ++i) {
            ans = n1 + n2;
            n2 = n1;
            n1 = ans;
        }
        return ans;
    }
};