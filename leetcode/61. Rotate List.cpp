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
private:

    int listSize(ListNode *head) {
        if (head == nullptr) return 0;
        return 1 + listSize(head->next);
    }

public:

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        int n = listSize(head);
        int shifts = k % n;

        if (shifts == 0) return head;

        ListNode *curr = head;
        for (int i = 0; i < n - shifts - 1; i++) {
            curr = curr->next;
        }

        cout << curr->val;

        ListNode *linkHead = curr->next;
        curr->next = nullptr;
        
        curr = linkHead;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head;
        head = linkHead;

        return head;
    }
};