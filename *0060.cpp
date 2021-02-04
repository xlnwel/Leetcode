#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int nf = 1;
        for (int i = 1; i < n; ++i)
            nf *= i;
        string s(n, '0');
        --k;
        vector<bool> used(n, false);
        for (auto i = 0; i < n; ++i) {
            int j = -1;
            for (auto a = k / nf; a >= 0; --a) {
                while (used[++j]); 
            }
            s[i] = j + '1';
            used[j] = true;
            k %= nf;
            nf /= max(1, n - 1 - i); 
        }
        return s;
    }
};