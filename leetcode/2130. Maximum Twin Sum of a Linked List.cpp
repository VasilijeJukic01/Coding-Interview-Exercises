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
    void maxSum(ListNode* forward, ListNode* &head, int &maxima) {
        if (forward == nullptr) return;
        maxSum(forward->next, head, maxima);
        maxima = max(maxima, forward->val + head->val);
        head = head->next;
    }

    int pairSum(ListNode* head) {
        int maxima = 0;
        maxSum(head, head, maxima);
        return maxima;
    }
};