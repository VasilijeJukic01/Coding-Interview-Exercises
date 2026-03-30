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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* link = new ListNode(INT_MAX);
        ListNode* prev = link;
        ListNode* curr = head;

        int skipValue = INT_MAX;
        while (curr->next) {
            if (curr->val == curr->next->val) {
                skipValue = curr->val;
            }
            if (curr->val != skipValue) {
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }

        if (curr && curr->val != skipValue) {
            prev->next = curr;
            prev = prev->next;
        }
        prev->next = nullptr;

        ListNode* tmp = link;
        head = link->next;
        delete tmp;

        return head;
    }
};