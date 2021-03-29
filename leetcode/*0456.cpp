#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), k = numeric_limits<int>::min();
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < k) 
                return true;
            while(!s.empty() && s.top() < nums[i]) { 
                k = max(k, s.top()); 
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};