#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        for (auto x: pushed) {
            s.push(x);
            while (i != popped.size() && !s.empty() && popped[i] == s.top()) {
                s.pop();
                ++i;
            }
        }
        return s.empty();
    }
};