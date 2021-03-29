#include <string>
#include <bitset>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        if (puzzles.empty() || words.empty())
            return {};

        unordered_map<int, int> word_compressed_freq;
        for (auto i = 0; i != words.size(); ++i) {
            int w = 0;
            for (auto j = 0; j != words[i].size(); ++j)
                w |= 1 << (words[i][j] - 'a');
            ++word_compressed_freq[w];
        }

        vector<int> first(puzzles.size());
        for (auto i = 0; i != puzzles.size(); ++i) {
            first[i] = 1 << (puzzles[i][0] - 'a');
        }

        vector ans(puzzles.size(), 0);
        for (auto i = 0; i != puzzles.size(); ++i) {
            for (auto s: subset(puzzles[i])) {
                ans[i] += s & first[i]? word_compressed_freq[s]: 0;
            }
        }
        return ans;
    }
private:
    vector<int> subset(const string& s) {
        vector<int> ans(1);
        ans.reserve(128);   // 128 = 2^s.size(), where s.size() = 7
        for (auto i = 0; i != s.size(); ++i) {
            int n = ans.size();
            for (auto j = 0; j != n; ++j) {
                auto x = ans[j] | (1 << (s[i] - 'a'));
                ans.push_back(x);
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        if (puzzles.empty() || words.empty())
            return {};
        vector<int> first(puzzles.size());
        vector<bitset<26>> pletters(puzzles.size());

        unordered_map<bitset<26>, int> word_compressed_freq;

        for (auto i = 0; i != words.size(); ++i) {
            bitset<26> wletters;
            for (auto j = 0; j != words[i].size(); ++j)
                wletters.set(words[i][j] - 'a');
            ++word_compressed_freq[wletters];
        }
        for (auto i = 0; i != puzzles.size(); ++i) {
            first[i] = puzzles[i][0] - 'a';
            for (auto j = 0; j != puzzles[i].size(); ++j)
                pletters[i].set(puzzles[i][j] - 'a');
        }

        vector ans(puzzles.size(), 0);
        for (auto i = 0; i != pletters.size(); ++i) {
            for (auto s: subset(pletters[i])) {
                ans[i] += s[first[i]]? word_compressed_freq[s]: 0;
            }
        }
        return ans;
    }
private:
    vector<bitset<26>> subset(bitset<26> b) {
        vector<bitset<26>> ans(1);
        for (auto i = 0; i != 26; ++i) {
            if (b[i]) {
                int n = ans.size();
                for (auto j = 0; j != n; ++j) {
                    auto bb = ans[j];
                    bb.set(i);
                    ans.push_back(std::move(bb));
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        if (puzzles.empty() || words.empty())
            return {};
        vector<bitset<26>> first(puzzles.size());
        vector<bitset<26>> wletters(words.size());
        vector<bitset<26>> pletters(puzzles.size());

        for (auto i = 0; i != words.size(); ++i) {
            for (auto j = 0; j != words[i].size(); ++j)
                wletters[i].set(words[i][j] - 'a');
        }
        for (auto i = 0; i != puzzles.size(); ++i) {
            first[i].set(puzzles[i][0] - 'a');
            for (auto j = 0; j != puzzles[i].size(); ++j)
                pletters[i].set(puzzles[i][j] - 'a');
        }

        vector ans(puzzles.size(), 0);
        for (auto i = 0; i != pletters.size(); ++i) {
            for (auto j = 0; j != wletters.size(); ++j) {
                if ((pletters[i] | ~wletters[j]).all() && (~first[i] | wletters[j]).all())
                    ++ans[i];
            }
        }
        return ans;
    }
};


class Solution3 {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        if (puzzles.empty() || words.empty())
            return {};
        vector first(puzzles.size(), 'a');
        vector<unordered_set<char>> letters;

        for (auto i = 0; i != puzzles.size(); ++i) {
            first[i] = puzzles[i][0];
            letters.emplace_back(puzzles[i].begin(), puzzles[i].end());
        }

        vector ans(puzzles.size(), 0);
        for (auto k = 0; k != puzzles.size(); ++k) {
            for (auto i = 0; i != words.size(); ++i) {
                bool contains_first = false;
                for (auto j = 0; j != words[i].size(); ++j) {
                    if (first[k] == words[i][j])
                        contains_first = true;
                    if (letters[k].find(words[i][j]) == letters[k].end()) {
                        contains_first = false;
                        break;
                    }
                }
                if (contains_first)
                    ++ans[k];
            }
        }
        return ans;
    }
};
