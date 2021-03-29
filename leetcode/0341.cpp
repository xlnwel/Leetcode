#include <vector>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
        i = v.begin();
    }
    
    int next() {
        return *i++;
    }
    
    bool hasNext() {
        return i != v.end();
    }
private:
    void dfs(const vector<NestedInteger>& l) {
        for (auto itr = l.begin(); itr != l.end(); ++itr) {
            if (itr->isInteger())
                v.push_back(itr->getInteger());
            else
                dfs(itr->getList());
        }
    }
    vector<int> v;
    vector<int>::iterator i;
};
