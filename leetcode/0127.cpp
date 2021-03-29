#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!contains(words, endWord))
            return 0;
        words.insert(beginWord);
        unordered_set<string> l1, r1, tmp;
        l1.insert(beginWord);
        r1.insert(endWord);
        int l = 0, r = 1;
        bool flag = true;
        while (!l1.empty() && !r1.empty()) {
            auto& search_set = flag? l1: r1;
            auto& other_set = flag? r1: l1;
            flag? ++l: ++r;
            for (auto itr = search_set.begin(); itr != search_set.end(); ++itr) {
                auto s = *itr;
                words.erase(s);
                for (auto i = 0; i != s.size(); ++i) {
                    auto old = s[i];
                    for (auto c = 'a'; c <= 'z'; ++c) {
                        if (c == old)
                            continue;
                        s[i] = c;
                        if (contains(words, s)) {
                            if (contains(other_set, s)) 
                                return l + r;
                            tmp.insert(s);
                        }
                    }
                    s[i] = old;
                }
            }
            swap(search_set, tmp);
            tmp = {};
            flag = !flag;
        }
        return 0;
    }
private:
    bool contains(const unordered_set<string>& words, const string& s) {
        return words.find(s) != words.end();
    }
};

class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ws = unordered_set(wordList.begin(), wordList.end());
        if (ws.count(endWord) == 0 || beginWord == endWord)
            return 0;
        ws.insert(beginWord);
        unordered_set<string> w1;   // words on the border, starting from beginWord
        unordered_set<string> w2;   // words on the border, starting from endWord
        unordered_set<string> tmp;
        w1.insert(beginWord);
        w2.insert(endWord);
        bool flag = true;   // broaden w1 if true; otherwise, w2 
        string s;
        int n = 1;
        while (!has_intersection(w1, w2)) {
            auto& x = flag? w1: w2;
            auto& y = flag? w2: w1;
            for (auto itr = x.begin(); itr != x.end(); ++itr) {
                ws.erase(*itr);
                insert_next(*itr, tmp);
            }
            if (x.empty())
                return 0;
            x = std::move(tmp);
            tmp.clear();
            ++n;
            flag = !flag;
        }
        return n;
    }
private:
    bool has_intersection(const unordered_set<string>& w1, const unordered_set<string>& w2) {
        for (auto itr = w1.begin(); itr != w1.end(); ++itr) {
            if (w2.count(*itr))
                return true;
        }
        return false;
    }
    void insert_next(string s, unordered_set<string>& w) {
        // for every letter, change it to any other letter and check if s in ws
        for (auto itr = s.begin(); itr != s.end(); ++itr) {
            auto x = *itr;
            for (auto c = 'a'; c <= 'z'; ++c) {
                *itr = c;
                if (ws.count(s)) {  // if s in ws, remove s from ws and return s
                    w.insert(s);
                }
            }
            *itr = x;
        }
    }
    unordered_set<string> ws;
};