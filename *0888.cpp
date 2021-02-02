#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        auto sumA = accumulate(A.begin(), A.end(), 0);
        auto sumB = accumulate(B.begin(), B.end(), 0);

        if (sumA == sumB)
            return {0, 0};

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        auto y = (sumA - sumB) / 2;
        for (auto i = 0, j = 0; i != A.size() && j != B.size();) {
            auto x = A[i] - B[j];
            if (x == y) 
                return {A[i], B[j]};
            if (x < y)
                ++i;
            else
                ++j;
        }
        return {0}; // never reaching here as a solution is guaranteed
    }
};