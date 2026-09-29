/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void solve(Node* head, stack<Node*>& st) {
        Node* curr = head;
        while (curr) {
            st.push(curr);
            solve(curr->child, st);
            curr = curr->next;
        }
    }

    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;

        stack<Node*> st;
        solve(head, st);

        Node* flattened = st.top();
        st.pop();

        while (!st.empty()) {
            Node* node = st.top();
            flattened->prev = node;
            node->next = flattened;
            flattened = node;

            if (node->child) node->child = nullptr;

            st.pop();
        }

        return flattened;
    }
};