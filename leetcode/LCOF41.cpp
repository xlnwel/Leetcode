#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (top.empty() || num < top.top()) {
            bot.push(num);
            balance();
        }
        else {
            top.push(num);
            balance();
        }
    }
    
    double findMedian() {
        if (top.size() == bot.size())
            return (top.top() + bot.top()) * .5;
        return top.top();
    }
private:
    void balance() {
        if (top.size() > bot.size()+1) {
            auto x = top.top();
            top.pop();
            bot.push(x);
        }
        else if (top.size() < bot.size()) {
            auto x = bot.top();
            bot.pop();
            top.push(x);
        }
    }
    priority_queue<int, vector<int>, std::greater<int>> top;
    priority_queue<int> bot;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */