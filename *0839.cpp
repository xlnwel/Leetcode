#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        v.resize(strs.size());
        for (int i = 0; i != strs.size(); ++i) {
            v[i] = i;
        }
        for (int i = 0; i != strs.size(); ++i) {
            for (int j = i+1; j != strs.size(); ++j) {
                if (find(i) == find(j))
                    continue;
                if (check(strs[i], strs[j]))
                    v[find(j)] = find(i);
            }
        }
        int ans = 0;
        for (auto i = 0; i != v.size(); ++i) {
            if (i == v[i])
                ++ans;
        }
        return ans;
    }
private:
    bool check(const string& s1, const string& s2) {
        int mis = 0;
        for (int i = 0; i != s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++mis;
            if (mis > 2)
                return false;
        }
        return true;
    }
    int find(int x) {
        if (v[x] != x)
            v[x] = find(v[x]);
        return v[x];
    }
    vector<int> v;
};