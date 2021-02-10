#include <vector>

using namespace std;


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2)
            return arr.size();
        bool greater = arr[1] < arr[0];
        int cur = arr[0] == arr[1]? 1: 2;
        int ans = cur;
        for (auto i = 2; i != arr.size(); ++i) {
            if (arr[i] == arr[i-1]) {
                cur = 1;
            }
            else if (cur == 1 || greater != (arr[i] > arr[i-1])) {
                cur = 2;
                greater = arr[i] < arr[i-1];
            }
            else {
                ++cur;
                ans = max(ans, cur);
                greater = !greater;
            }
        }
        return max(cur, ans);
    }
};