#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    using ir = pair<int, char>;
    string intToRoman(int num) {
        vector<ir> v1{
            ir(1000, 'M'),
            ir(100, 'C'),
            ir(10, 'X'),
            ir(1, 'I'),
        };
        vector<ir> v2{
            ir(500, 'D'),
            ir(50, 'L'),
            ir(5, 'V'),
        };
        string ans;
        for (auto i = 0; i != v1.size(); ++i) {
            auto [n, c] = v1[i];
            auto q = num / n;
            if (q == 9) {
                ans = ans + c + v1[i-1].second;
            }
            else if (q == 4) {
                ans = ans + c + v2[i-1].second;
            }
            else {
                if (q >= 5)
                    ans += v2[i-1].second;
                for (auto j = 0; j != q % 5; ++j)
                    ans += c;
            }
            num %= n;
        }
        return ans;
    }
};