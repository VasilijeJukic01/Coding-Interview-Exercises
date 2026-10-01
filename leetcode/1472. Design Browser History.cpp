struct Node {
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class List {
private:
    Node* head;
    Node* tail;

    Node* curr;
public:
    List() {}

    void init (string home) {
        this->head = new Node("/");
        this->tail = new Node("/");
        head->next = tail;
        tail->prev = head;

        Node* homePage = new Node(home);
        head->next = homePage;
        homePage->prev = head;
        homePage->next = tail;
        tail->prev = homePage;

        curr = homePage;
    }

    void push(string url) {
        Node* node = new Node(url);
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;

        curr->next = node;
        node->prev = curr;
        curr = curr->next;
    }

    string forward(int steps) {
        int cnt = 0;
        while (curr->next != tail && cnt < steps) {
            curr = curr->next;
            cnt++;
        }
        return curr->val;
    }

    string back(int steps) {
        int cnt = 0;
        while (curr->prev != head && cnt < steps) {
            curr = curr->prev;
            cnt++;
        }
        return curr->val;
    }
};

class BrowserHistory {  
    List list;
public:
    BrowserHistory(string homepage) {
        list.init(homepage);
    }
    
    void visit(string url) {
        list.push(url);
    }
    
    string back(int steps) {
        return list.back(steps);
    }
    
    string forward(int steps) {
        return list.forward(steps);
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */