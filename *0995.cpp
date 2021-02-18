#include <vector>
#include <numeric>

using namespace std;


class Solution2 {
public:
    int minKBitFlips(vector<int>& A, int K) {
        return helper(A.begin(), A.end(), K);
    }
private:
    int helper(vector<int>::iterator b, vector<int>::iterator e, int K) {
        if (e - b < K)
            return accumulate(b, e, 0) == e - b? 0: -1;
        else if (e - b == K) {
            int sum = accumulate(b, e, 0);
            if (sum == K)
                return 0;
            if (sum == 0)
                return 1;
            return -1;
        }
        if (*(e-1) == 1) {
            return helper(b, e-1, K);
        }
        else {
            for_each(e-K, e, [](int &x) { return x ^= 1; });
            int ans = helper(b, e-1, K);
            for_each(e-K, e, [](int &x) { return x ^= 1; });
            return ans == -1? -1: ans + 1;
        }
    }
};