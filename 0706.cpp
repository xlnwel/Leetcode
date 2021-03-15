#include <list>
#include <utility>
#include <vector>

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(): v(mod) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto k = key % mod;
        for (auto itr = v[k].begin(); itr != v[k].end(); ++itr) {
            if (key == itr->first) {
                itr->second = value;
                return;
            }
        }
        v[k].emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto k = key % mod;
        for (auto itr = v[k].begin(); itr != v[k].end(); ++itr) {
            if (key == itr->first)
                return itr->second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto k = key % mod;
        for (auto itr = v[k].begin(); itr != v[k].end(); ++itr) {
            if (itr->first == key) {
                v[k].erase(itr);
                return;
            }
        }
    }
private:
    vector<list<pair<int, int>>> v;
    static constexpr int mod = 10007;
};
