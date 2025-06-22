/*
You are a quality control engineer at a high-tech manufacturing plant. Parts move along a single assembly line, and each part 
has a unique integer serial number. Your system has just received a list of serial numbers for a batch of parts that are known to 
be defective.
Your task is to write a program that removes all defective parts from the assembly line before they proceed to the final product. 
The assembly line is represented as a singly linked list of Part objects, and the list of defective serial numbers is given as an 
array of integers.

You are given:
- defectiveSerials: An array of integers representing the serial numbers of known defective parts.
- head: The first Part object on the assembly line, which is the head of a singly linked list. Each Part object has two properties:
	- serialNumber (an integer)
	- next (a pointer to the next Part on the line, or null if it's the last one)
	
Return the head of the modified assembly line after removing all parts whose serialNumber is present in the defectiveSerials list.

Example:

Input:
defectiveSerials = [3, 8, 10]
assemblyLine = 1 -> 3 -> 5 -> 8 -> 9 -> 10 -> 12

Process:
The part with serialNumber 3 is defective and is removed. The line becomes 1 -> 5 -> 8 -> ...
The part with serialNumber 8 is defective and is removed. The line becomes 1 -> 5 -> 9 -> ...
The part with serialNumber 10 is defective and is removed. The line becomes 1 -> 5 -> 9 -> 12.

Output: The head of the list 1 -> 5 -> 9 -> 12.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

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
    ListNode *removeSerials(std::vector<int> &defectiveSerials, ListNode *head) {
        std::unordered_set<int> serialsSet(defectiveSerials.begin(), defectiveSerials.end());

        ListNode* stub = new ListNode(0);
        stub->next = head;

        ListNode* prev = stub;
        ListNode* curr = head;

        while (curr) {
            if (serialsSet.count(curr->val)) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = stub->next;
        delete stub;

        return newHead;
    }
};

int main() {
    std::vector<int> serials = {3, 8, 10};
    std::vector<int> input_nums = {1, 3, 5, 8, 9, 10, 12};
    ListNode* head = create_linked_list(input_nums);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    ListNode* result_head = sol.removeSerials(serials, head);

    std::cout << "Reordered List: ";
    print_linked_list(result_head);
    
    return 0;
}
