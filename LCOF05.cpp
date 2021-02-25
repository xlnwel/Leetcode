#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        size_t pos = 0;
        if (s[pos] == ' ')
            s.replace(pos, 1, "%20");
        while((pos = s.find(" ", pos)) != string::npos) {
           s.replace(pos, 1, "%20");
       }
       return s;
    }
};

class Solution2 {
public:
    string replaceSpace(string s) {
        stringstream ss;
        for (const auto c: s) {
            if (c == ' ')
                ss << "%20";
            else
                ss << c;
        }
        return ss.str();
    }
};
