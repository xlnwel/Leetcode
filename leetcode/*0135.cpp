#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        candies[0] = 1;
        for (auto i = 1; i != ratings.size(); ++i) {
            candies[i] = ratings[i] > ratings[i-1]?candies[i-1]+1:1;
        }
        for (int i = ratings.size()-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                candies[i] = candies[i+1]+1;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

class Solution2 {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        candies[0] = 1;
        for (auto i = 1; i != ratings.size(); ++i) {
            candies[i] = ratings[i] > ratings[i-1]?candies[i-1]+1:1;
            for (auto j = i; j > 0 && ratings[j] < ratings[j-1] && candies[j] >= candies[j-1]; --j) {
                candies[j-1] = candies[j]+1;
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};