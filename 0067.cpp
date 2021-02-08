#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size())
            swap(a, b);
        int i = 1;
        bool carry=false, m=false, n=false;
        int la = a.size();
        int lb = b.size();
        for (; i <= la; ++i) {
            m = a[la-i] == '1';
            n = b[lb-i] == '1';
            b[lb-i] = m ^ n ^ carry + '0';
            carry = (m & n) | (m & carry) | (n & carry);
        }
        for (; i <= lb; ++i) {
            n = (b[lb-i] == '1');
            b[lb-i] = carry ^ n + '0';
            carry = carry & n;
        }
        if (carry)
            b = '1' + b;
        return b;
    }
};
