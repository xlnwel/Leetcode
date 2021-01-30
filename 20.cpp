#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string s2;  // using string can call back without checking if it's empty
        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[')
                s2 += c;
            else {
                if (c == ')' && s2.back() == '(')
                    s2.pop_back();
                else if (c == '}' && s2.back() == '{')
                    s2.pop_back();
                else if (c == ']' && s2.back() == '[')
                    s2.pop_back();
                else
                    return false;
            }
        }
        return s2.empty();
    }
};