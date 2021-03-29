#include <vector>
#include <unordered_map>
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int i = 0;
        unordered_map<int, int> m;
        for (; i != A.size() && m.size() != K; ++i)
            ++m[A[i]];
        if (m.size() < K)
            return 0;
        int ans = 1;
        for (int j = -1; i != A.size(); ++i) {
            if (++m[A[i]] == 1) {   // new integer
                while(--m[A[++j]]);
                m.erase(A[j]);
            }
            unordered_map<int, int> m2;
            for (int k = i; k > j; --k) {
                ++m2[A[k]];
                if (m2.size() == K) {
                    ans += k-j;
                    break;
                }
            }
        }
        return ans;
    }
};