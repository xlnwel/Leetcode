#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int flips = 0;
        int n = 0;
        for (auto i = 0, j = 0; i != A.size(); ++i) {
            if (i-K >= 0 && A[i-K] == 2)
                --flips;
            if ((flips&1) != A[i])
                continue;
            if (i > A.size() - K)
                return -1;
            ++flips;
            ++n;
            A[i] = 2;
        }
        return n;
    }
};

class Solution2 {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> q;
        int n = 0;
        for (auto i = 0; i != A.size(); ++i) {
            if (q.front() == i - K)
                q.pop();
            if ((q.size() & 1) == A[i]) {
                if (i > A.size()-K)
                    return -1;
                q.push(i);
                ++n;
            }
        }
        return n;
    }
};

class Solution3 {
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