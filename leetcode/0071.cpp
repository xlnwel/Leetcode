#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() == 1)
            return path;
        int n = 0;
        for (auto i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (i + 1 == path.size())   // "/" in the end, ignore it
                    break;
                if (path[i+1] == '/') {    // consecutive "//", ignore first "/"
                    continue;
                }
                if (path[i+1] == '.') {
                    if (i + 2 == path.size() || path[i+2] == '/') {   // "/." in the end or "/./", ignore them
                        ++i;
                        continue;
                    }
                    if (path[i+2] == '.' && (i + 3 == path.size() || path[i+3] == '/')) {     // "/../": n rolls back to the previous "/". i advance to the next "/"
                        i += 2;
                        while (n > 0 && path[--n] != '/');
                        continue;
                    }
                }
            }
            assert(path[i] == '/');
            // cout << i << path[i] << endl;
            while (i + 1 < path.size() && path[i+1] != '/') {
                path[n++] = path[i++];
            }
            path[n++] = path[i];
            // cout << i << path.substr(0, n) << endl;
        }
        if (n == 0)
            return "/";
        return path.substr(0, n);
    }
};
