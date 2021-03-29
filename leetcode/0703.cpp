#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int kk, vector<int>& nums): k(kk), q(nums.begin(), nums.end()) {
        while (q.size() > k) {
            q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> q;
};
