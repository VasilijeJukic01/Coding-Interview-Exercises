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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *left = new ListNode(-1);
        ListNode *right = new ListNode(-1);

        ListNode *leftHead = left;
        ListNode *rightHead = right;

        ListNode *curr = head;
        while (curr) {
            if (curr->val < x) {
                left->next = curr;
                left = left->next;
            }
            else {
                right->next = curr;
                right = right->next;
            }
            curr = curr->next;
        }
        left->next = nullptr;
        right->next = nullptr;

        ListNode *target = rightHead;
        rightHead = rightHead->next;
        delete target;

        left->next = rightHead;

        target = leftHead;
        leftHead = leftHead->next;
        delete target;

        head = leftHead;
        return head;
    }
};