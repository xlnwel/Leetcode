#include <vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> pos2per(row.size());
        for (auto i = 0; i != row.size(); ++i) {
            pos2per[row[i]] = i;
        }
        int ans = 0;
        for (auto i = 0; i != row.size(); i += 2) {
            int next = row[i] ^ 1;
            if (row[i+1] == next)
                continue;
            
            int person_to_swap = pos2per[next];
            row[person_to_swap] = row[i+1];
            pos2per[row[i+1]] = person_to_swap;
            
            ++ans;
        }
        return ans;
    }
};
