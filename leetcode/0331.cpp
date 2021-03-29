#include <string>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = 0, m = 0;
        for (auto i = 0; i < preorder.size();) {
            if (preorder[i] == '#')
                ++m;
            else {
                ++n;
                while (i+1 != preorder.size() && preorder[i+1] != ',')
                    ++i;
            }
            if (m > n && i != preorder.size()-1)
                return false;
            i += 2;
        }
        return m == n+1;
    }
};
