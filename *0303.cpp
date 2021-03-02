#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        v.resize(nums.size()+1);
        v[0] = 0;
        for (auto i = 1; i != v.size(); ++i)
            v[i] = v[i-1] + nums[i-1];
    }
    
    int sumRange(int i, int j) {
        return v[j+1] - v[i];
    }
private:
    vector<int> v;
};
