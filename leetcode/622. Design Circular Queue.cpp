class MyCircularQueue {
public:
    vector<int> q;
    int back = -1;
    int front = -1;
    int capacity = 0;

    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k); 
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        if (back == -1 && front == -1) {
            back = 0;
            front = 0;
        }
        else back = (back + 1) % capacity;
        q[back] = value;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        if (back == front) {
            back = -1;
            front = -1;
        }
        else front = (front + 1) % capacity;

        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[back];
    }
    
    bool isEmpty() {
        return back == -1 && front == -1;
    }
    
    bool isFull() {
        return (back + 1) % capacity == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */