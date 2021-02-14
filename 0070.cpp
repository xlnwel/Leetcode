#include <utility>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        int i_1=1, i_2=1;
        for (int i = 2; i <= n; ++i) {
            i_2 = i_1 + i_2;
            swap(i_1, i_2);
        }
        return i_1;
    }
};