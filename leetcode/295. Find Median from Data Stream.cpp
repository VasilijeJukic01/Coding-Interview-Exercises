class MedianFinder {
public:
    priority_queue<int> leftPq;
    priority_queue<int, vector<int>, greater<int>> rightPq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftPq.push(num);
        rightPq.push(leftPq.top());
        leftPq.pop();

        if (rightPq.size() > leftPq.size()) {
            leftPq.push(rightPq.top());
            rightPq.pop();
        }
    }
    
    double findMedian() {
        if (leftPq.size() == rightPq.size()) {
            return (leftPq.top() + rightPq.top()) / 2.0;
        }
        return leftPq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */