#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        vector<Node*> visited(101, nullptr);
        stack<Node*> s;
        s.push(node);
        Node* ans = new Node(node->val);
        visited[node->val] = ans;
        while (!s.empty()) {
            node = s.top();
            s.pop();
            auto np = visited[node->val];
            for (auto p2: node->neighbors) {
                if (!visited[p2->val]) {
                    visited[p2->val] = new Node(p2->val);
                    s.push(p2);
                }
                np->neighbors.push_back(visited[p2->val]);

            }
        }
        return ans;
    }
};