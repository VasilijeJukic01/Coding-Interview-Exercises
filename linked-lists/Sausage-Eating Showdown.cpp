/*
It's the final round of the World Sausage-Eating Championship! Two legendary eaters, "The Chomper" and "The Mauler," face off. 
A long, continuous chain of sausages is laid out between them.

The rules are simple:
"The Chomper" starts at the beginning of the chain (the head).
"The Mauler" starts at the very end.
On the sound of the bell, they each eat one sausage link per second, moving towards the middle.
A showdown is declared "Perfectly Matched" if, at every single moment, both competitors are eating the exact same type of sausage. 
Your job, as the judge, is to analyze the sausage chain beforehand and predict if the showdown will be perfectly matched.

You are given:
- head: The first Sausage in the chain that The Chomper starts with. This is the head of a singly linked list.
Each Sausage object has:
- flavorCode (an integer representing a specific flavor, e.g., 5=Spicy Italian, 8=Applewood Smoked, 2=Classic Bratwurst)
- next (a pointer to the next Sausage in the chain)
Return true if the sequence of flavorCodes will result in a "Perfectly Matched" showdown, and false otherwise.
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
    bool isPerfectlyMatched(ListNode* head) {
        if (head == nullptr) return head;
		
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;        
    }
};

int main() {
    std::vector<int> input_nums = {1, 2, 3, 3, 2, 1};
    ListNode* head = create_linked_list(input_nums);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    std::cout << sol.isPerfectlyMatched(head);
    
    return 0;
}