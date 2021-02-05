#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = 0;
        int m = 0;
        for (int i = 0; i < path.size();) {
            if (path[i] == '/') {
                if (i + 1 == path.size())   // break if path ends
                    break;
                else if (path[i+1] == '.') {
                    if (i + 2 == path.size())   // break if path ends with . 
                        break;
                    else {
                        if (path[i+2] == '.' && (i + 3 >= path.size() || path[i+3] == '/')) {   // set n = m and skip to next / if ..
                            while (n > 0 && path[--n] != '/');
                            i += 3;
                            continue;
                        }
                        else if (path[i+2] == '/') {    // skip to next / if .
                            i += 2;
                            continue;
                        }
                        // do nothing if /.[^./]+
                    }
                }
                else  if (path[i+1] == '/'){ // jump over consecutive //
                    while (i+1 < path.size() && path[i+1] == '/')
                        ++i;
                    continue;
                }
            }
            assert(path[n] == '/' && path[i] == '/');
            m = n;
            while (i+1<path.size() && path[i+1] != '/') {
                path[++n] = path[++i];
            }
            path[++n] = path[++i];
        }
        if (n != 0 && path[n] == '/')
            --n;
        return path.substr(0, n+1);
    }
};