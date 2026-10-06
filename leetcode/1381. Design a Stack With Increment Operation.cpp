class CustomStack {
    int cap;
    vector<int> stack;
    vector<int> increments;
public:
    CustomStack(int maxSize) {
        this->cap = maxSize;
        increments.resize(cap, 0);
    }
    
    void push(int x) {
        if (stack.size() == cap) return;
        stack.push_back(x);
    }
    
    int pop() {
        if (stack.empty()) return -1;
        int n = stack.size();

        int val = stack.back();
        int acc = increments[n - 1];
        stack.pop_back();
        
        increments[n - 1] -= acc;
        if (!stack.empty()) {
            increments[n - 2] += acc;
        }
        
        return val + acc;
    }
    
    void increment(int k, int val) {
        int limit = min((int)stack.size(), k);
        if (limit > 0) {
            increments[limit - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */