#include <vector>
#include <stack>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n), r(n, n);
        
        stack<int> s;
        for (auto i = 0; i != n; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                r[s.top()] = i;
                s.pop();
            }
            l[i] = s.empty()? 0: s.top() + 1;// There was supposed to be another condition to predicate if heights[s.top()] == heights[i]. However, regarding the question only asks for the largest rectangle, the area of rectangle with heights[i] does not matter as it's the same as the one with heights[s.top()] 
            s.push(i);
        }
        int ans = 0;
        for (auto i = 0; i != n; ++i) {
            ans = max(heights[i] * (r[i] - l[i]), ans);
        }
        return ans;
    }
};