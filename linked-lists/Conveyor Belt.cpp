/*
You are Zorp, the diligent supervisor at the Starlight Assembly Plant. Your main job is to manage the Cosmic Conveyor Belt, 
which transports precious Star-Widgets for final assembly. The conveyor belt is a one-way system, much like a linked list, 
where each widget is linked to the next one in line.
A new re-sequencing procedure is being implemented. An operator can send a "shift pulse" of a certain strength, k, to the belt. 
A shift pulse of strength k causes the last k widgets on the belt to be unlinked from the end and moved to the very front, 
maintaining their relative order.

Your task is to write a program that simulates this re-sequencing procedure.
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

    int size(ListNode *head) {
        if (head == nullptr) return 0;
        return 1 + size(head->next);
    }

    ListNode* shiftPulse(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        int len = size(head);
        int counter = 0;

        ListNode *curr = head;
        ListNode *tail = head;

        while (tail->next) {
            tail = tail->next;
        }

        while (counter < (len - (k % len)) - 1) {
            counter++;
            curr = curr->next;
        }

        tail->next = head;
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};

int main() {
    std::vector<int> input_nums = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = create_linked_list(input_nums);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    ListNode* result_head = sol.shiftPulse(head, 2);

    std::cout << "Reordered List: ";
    print_linked_list(result_head);
    
    return 0;
}