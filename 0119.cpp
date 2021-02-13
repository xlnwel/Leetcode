#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        else if (rowIndex == 1)
            return {1, 1};
        vector<int> v{1, 1, 1}, v2{1, 1};
        for (auto i = 2; i <= rowIndex; ++i) {
            for (auto j = 1; j != v2.size(); ++j) {
                v[j] = v2[j-1] + v2[j];
            }
            v2 = std::move(v);
            v.resize(v2.size()+1, 1);
        }
        return v2;
    }
};