/*
You are a field agent on a critical mission. Your target is the "Midnight Express," a high-speed, automated cargo train 
transporting illicit materials. Your objective is to disrupt the shipment by remotely decoupling a specific carriage.
The train's carriages are linked sequentially, forming a chain that can be represented as a linked list. Your system interface 
can only traverse the train's network from the engine (the head) towards the caboose (the tail). Due to the train's velocity 
and your limited hacking window, you can only make a single forward pass through the carriage network data.

Your mission control has just given you the target_position: the position of the carriage to decouple, counted from the rear of 
the train. You must write a script to perform this operation.
*/

#include <iostream>
#include <vector>

// ------------------------------------------------------------------ //

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_linked_list(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// ------------------------------------------------------------------ //

class Solution {
public:
   ListNode* disruptShipment(ListNode* head, int target_position) {
        if (head == nullptr) return head;

        ListNode *stub = new ListNode(-1);

        stub->next = head;

        ListNode *fast = stub;
        ListNode *slow = stub;

        for (int i = 0; i < target_position; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *target = slow->next;
        slow->next = slow->next->next;
        delete target;

        ListNode* oldHead = stub->next;
        delete stub;
        
        return oldHead;  
    }
};

int main() {
    std::vector<int> input_nums = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = create_linked_list(input_nums);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    ListNode* result_head = sol.disruptShipment(head, 2);

    std::cout << "Reordered List: ";
    print_linked_list(result_head);
    
    return 0;
}