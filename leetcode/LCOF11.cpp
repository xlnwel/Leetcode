#include <vector>

using namespace std;


class Solution {
public:
    int minArray(vector<int>& numbers) {
        for (auto i = 1; i < numbers.size(); ++i) {
            if (numbers[i] < numbers[i-1])
                return numbers[i];
        }
        return numbers[0];
    }
};