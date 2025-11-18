class MyQueue {
public:
    stack<int> st;

    MyQueue() { }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> reversed;
        while (!st.empty()) {
            reversed.push(st.top());
            st.pop();
        }
        int val =  reversed.top();
        reversed.pop();
        while (!reversed.empty()) {
            st.push(reversed.top());
            reversed.pop();
        }
        return val;
    }
    
    int peek() {
        stack<int> reversed;
        while (!st.empty()) {
            reversed.push(st.top());
            st.pop();
        }
        int val =  reversed.top();
        while (!reversed.empty()) {
            st.push(reversed.top());
            reversed.pop();
        }
        return val;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */