/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        head = head->next;

        while (curr) {
            prev->next = curr->next;
            curr->next = prev;

            ListNode *save = prev->next;

            if (prev->next && prev->next->next)
                prev->next = prev->next->next;

            prev = save;
            if (prev == nullptr) break;

            curr = prev->next;
        }

        return head;
    }
};