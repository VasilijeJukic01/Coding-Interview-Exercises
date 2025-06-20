/*
A critical point in a linked list is defined as either a local maxima or a local minima.
- A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
- A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum 
distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. 
If there are fewer than two critical points, return [-1, -1].

Input: head = [5,3,1,2,5,1,2]
Output: [1,3]

Constraints:
The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105
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
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return {-1, -1};

        if (head->next->next == nullptr) return {-1, -1};

        ListNode* prev = head;
        ListNode *curr = head->next;

        std::vector<int> criticalPoints;

        int counter = 0;

        while (curr->next) {
            int x = curr->val;
            int leftValue = prev->val;
            int rightValue = curr->next->val;

            if ((x < leftValue && x < rightValue) || (x > leftValue && x > rightValue)) {
                criticalPoints.push_back(counter);
            }

            prev = curr;
            curr = curr->next;
            counter++;
        }

        if (criticalPoints.empty() || criticalPoints.size() == 1) return {-1,-1};

        int maxDistance = criticalPoints[criticalPoints.size() - 1] - criticalPoints[0];
        int minDistance = maxDistance;

        for (int i = 1; i < criticalPoints.size(); i++) {
            int dx = criticalPoints[i] - criticalPoints[i-1];
            if (dx < minDistance) {
                minDistance = dx;
            }
        }
        
        return {minDistance, maxDistance};
    }
};

int main() {
    std::vector<int> input_nums = {5, 3, 1, 2, 5, 1, 2};
    ListNode* head = create_linked_list(input_nums);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    std::vector<int> result = sol.nodesBetweenCriticalPoints(head);

    std::cout << "Result: " << result[0] << " " << result[1] << std::endl;    
    return 0;
}