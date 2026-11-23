class MedianFinder {
    priority_queue<int> decreasing;
    priority_queue<int, vector<int>, greater<int>> increasing;
    bool even = true;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        even = !even;
        if(!even){
            decreasing.push(num);
            increasing.push(decreasing.top());
            decreasing.pop();
        } else {
            increasing.push(num);
            decreasing.push(increasing.top());
            increasing.pop();
        }
    }
    
    double findMedian() {
        if(!even) return increasing.top();
        return (decreasing.top() + increasing.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */