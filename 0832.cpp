#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto i = 0; i != A.size(); ++i) {
            int a = -1;
            int b = A[0].size();
            while (++a <= --b) {
                swap(A[i][a], A[i][b]);
                A[i][a] ^= 1;
                if (a != b)
                    A[i][b] ^= 1;
            }
        }
        return A;
    }
};
