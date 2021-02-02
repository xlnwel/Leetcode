#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        auto sumA = accumulate(A.begin(), A.end(), 0);
        auto sumB = accumulate(B.begin(), B.end(), 0);
        auto a_b = (sumA - sumB) / 2;

        int i = 0, j = 0;
        int gap;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        while (i != A.size() && j != B.size()) {
            gap = A[i] - B[j];
            if (gap == a_b)
                return {A[i], B[j]};
            else if (gap > a_b)
                ++j;
            else
                ++i;
        }
        return {0, 0};
    }
};