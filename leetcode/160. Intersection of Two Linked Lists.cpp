/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr) return headB;
        if (headB == nullptr) return headA;

        ListNode* a = headA;
        ListNode* b = headB;

        int lenA = 0, lenB = 0;

        while (a) {
            a = a->next;
            lenA++;
        }
        while (b) {
            b = b->next;
            lenB++;
        }

        a = headA;
        b = headB;

        while (lenA > lenB) {
            lenA--;
            a = a->next;
        }
        while (lenB > lenA) {
            lenB--;
            b = b->next;
        }

        for (int i = 0; i < lenA; i++) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }
        
        return nullptr;
    }
};