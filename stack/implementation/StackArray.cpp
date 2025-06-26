#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>

class Stack {
private:
    vector<T> data;
public:

    void push(T value) {
        data.push_back(value);
    }
    
    void pop() {
        if (isEmpty()) {
            throw logic_error("Cannot pop from an empty stack.");
        }
        data.pop_back();
    }
    
    T top() {
        if (isEmpty()) {
            throw logic_error("Cannot peek at an empty stack.");
        }
        return data.back();
    }

    bool isEmpty() {
        return data.empty();
    }
    
    int size() {
        return data.size();
    }
};

int main() {
   Stack<int> s;
   s.push(1);
   s.push(2);
   s.push(3);
   
   cout << "Top element is: " << s.top() << endl; 
   
   s.pop();
   
   cout << "Top element after pop is: " << s.top() << endl;
   
   s.pop();
   s.pop();
   
   cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
