class RecentCounter {
public:
    queue<int> q;
    int counter;
    
    RecentCounter() {
        this->counter = 0;
    }
    
    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000) {
            q.pop();
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */