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

    int listSize(ListNode* l) {
        int len = 0;
        while (l) {
            len++;
            l = l->next;
        }
        return len;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* link;

        int n, carry = 0;
        bool firstList = true;
        if (listSize(l1) > listSize(l2)) {
            n = listSize(l1);
        }
        else {
            firstList = false;
            n = listSize(l2);
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            int val = 0;
            if (firstList) {
                val = q ? q->val : 0;
                sum = p->val + val + carry;
                carry = sum / 10;
                p->val = sum % 10;
                if (!p->next) link = p;
            }
            else {
                val = p ? p->val : 0;
                sum = q->val + val + carry;
                carry = sum / 10;
                q->val = sum % 10;
                if (!q->next) link = q;
            }
            if (p) p = p->next;
            if (q) q = q->next;
        }

        if (carry != 0) {
            if (firstList) link->next = new ListNode(carry);
            else link->next = new ListNode(carry);
        }
        
        return firstList ? l1 : l2;
    }
};