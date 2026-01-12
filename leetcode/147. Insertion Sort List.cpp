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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* i = head->next;
        ListNode* prevI = head;

        while (i) {
            ListNode* j = head;
            if (i->val <= j->val) {
                prevI->next = i->next;
                i->next = j;
                head = i;
                i = prevI->next;
                continue;
            }
            // Find place where to insert
            while (j->next != i) {
                if (j->next->val > i->val) break;
                j = j->next;
            }
            // No insertion needed
            if (j->next == i) {
                prevI = i;
                i = i->next;
                continue;
            }
            // Insert
            prevI->next = i->next;
            i->next = j->next;
            j->next = i;

            i = prevI->next;
        }

        return head;
    }
};