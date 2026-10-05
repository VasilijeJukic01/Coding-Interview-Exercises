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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* itr = head;
        ListNode* chain = head;
        
        int sum = 0;
        while (itr->next) {
            if (itr->next->val == 0) {
                chain->next->val = sum;
                chain = chain->next;
                sum = 0;
            }
            else {
                sum += itr->next->val;
            }
            itr = itr->next;
        }
        chain->next = nullptr;

        return head->next;
    }
};