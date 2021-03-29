#include <list>
#include <vector>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet(): v(mod) {
    }
    
    void add(int key) {
        if (contains(key))
            return;
        auto k = key % mod;
        v[k].push_back(key);
    }
    
    void remove(int key) {
        auto k = key % mod;
        for (auto itr = v[k].begin(); itr != v[k].end(); ++itr) {
            if (*itr == key) {
                v[k].erase(itr);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto k = key % mod;
        for (auto itr = v[k].begin(); itr != v[k].end(); ++itr) {
            if (key == *itr)
                return true;
        }
        return false;
    }
private:
    vector<list<int>> v;
    static constexpr int mod = 10007;
};
