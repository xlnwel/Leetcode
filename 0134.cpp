#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty())
            return 0;
        int rest = 0;
        int i = 0, k = 0;
        bool first = true;
        do {
            if ((rest += gas[i] - cost[i]) < 0) {
                if (!first)
                    return -1;
                for (++i; i != gas.size() && gas[i] < cost[i]; ++i) {}
                if (i == gas.size())
                    return -1;
                rest = gas[i] - cost[i];
                k = i;
            }
            if (++i == gas.size()) {
                i = 0;
                first = false;
            }
        } while (i != k);
        return k;
    }
};
