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
    int size(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int n = size(head);

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* linkStart = dummy;
        ListNode* linkEnd = head;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = head->next;
        int totalGroups = 0;
        for (int i = 0; i < n; i++) {
            if (totalGroups == n / k) {
                linkStart->next = curr;
                break;
            }

            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (i < n - 1) nxt = nxt->next;

            if ((i + 1) % k == 0) {
                // Reset + Chain
                linkStart->next = prev;
                linkStart = linkEnd;
                linkEnd = curr;

                prev == nullptr;
                totalGroups++;
            }
        }

        if (n % k == 0) linkStart->next = nullptr;

        head = dummy->next;
        delete dummy;

        return head;
    }
};