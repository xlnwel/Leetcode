#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        if (S.size() < 2)
            return S;
        int i = 1, j = 0;
        while (i != S.size()) {
            if (j >= 0 && S[i] == S[j]) {
                --j;
            }
            else {
                S[++j] = S[i];
            }
            ++i;
        }
        return S.substr(0, j+1);
    }
};
