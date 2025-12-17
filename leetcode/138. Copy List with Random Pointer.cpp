/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* copy = new Node(head->val);
        unordered_map<Node*, Node*> map;
        map[head] = copy;

        Node* curr = head->next;
        Node* currCopy = copy;
        while (curr) {
            Node* node = new Node(curr->val);
            currCopy->next = node;

            map[curr] = node;

            curr = curr->next;
            currCopy = currCopy->next;
        }

        curr = head;
        currCopy = copy;

        while (currCopy) {
            currCopy->random = map[curr->random];

            curr = curr->next;
            currCopy = currCopy->next;
        }

        return copy;
    }
};