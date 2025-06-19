/*
You are the Guild Master organizing an expedition. The adventurers are lined up as a singly linked list, and you are given the 
leader of this line. Your task is to split the line into two teams: the Vanguard and the Rearguard. You must reorder the line so 
that all Vanguard members are at the front, followed by all Rearguard members.
The team assignment is done by position in the original line:
- The first adventurer joins the Vanguard.
- The second adventurer joins the Rearguard.
- The third joins the Vanguard, the fourth the Rearguard, and so on.

Note that the relative order of adventurers inside both the Vanguard and the Rearguard teams must remain the same as it was in the 
initial line.
You must solve the problem by rearranging the line in-place, using O(1) extra memory and in O(n) time. Return the leader of the 
reordered line.
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
    ListNode* solution(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;

        ListNode *vanguard = head;
        ListNode *rearguard = head->next;

        ListNode *link = rearguard;

        while (rearguard) {
            vanguard->next = rearguard->next;
            if (rearguard->next) {
                rearguard->next = rearguard->next->next;
            }

            if (vanguard->next) {
                vanguard = vanguard->next;
            }
            rearguard = rearguard->next;
        }

        vanguard->next = link;

        return head;
    }
};

int main() {
    std::vector<int> input_nums = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = create_linked_list(input_nums);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    ListNode* result_head = sol.solution(head);

    std::cout << "Reordered List: ";
    print_linked_list(result_head);
    
    return 0;
}