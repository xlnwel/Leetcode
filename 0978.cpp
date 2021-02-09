#include <vector>

using namespace std;


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2)
            return arr.size();
        bool greater = arr[0] < arr[1]; // if the next comparison is greater than
        int cur = arr[0] == arr[1]? 1: 2;
        int ans = cur;
        for (auto i = 1; i != arr.size(); ++i) {
            if (arr[i-1] == arr[i]) {
                cur = 1;
                continue;
            }
            if (cur == 1) {
                ++cur;
                greater = arr[i-1] < arr[i];
            }
            if ((greater && arr[i-1] > arr[i]) || (!greater && arr[i-1] < arr[i])) {
                ++cur;
                greater = !greater;
                ans = max(ans, cur);
            }
            else {
                greater = arr[i-1] < arr[i];
                cur = arr[i-1] == arr[i]? 1: 2;
            }
        }
        return ans;
    }
};