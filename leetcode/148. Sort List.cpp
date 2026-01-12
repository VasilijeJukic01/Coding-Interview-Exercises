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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);

        ListNode* merged = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                merged->next = list1;
                list1 = list1->next;
            }
            else {
                merged->next = list2;
                list2 = list2->next;
            }
            merged = merged->next;
        }

        merged->next = list1 ? list1 : list2;

        ListNode* tmp = dummy;
        dummy = dummy->next;
        delete tmp;

        return dummy;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = nullptr;

        ListNode* sortedL1 = sortList(list1);
        ListNode* sortedL2 = sortList(list2);
        return merge(sortedL1, sortedL2);
    }
};