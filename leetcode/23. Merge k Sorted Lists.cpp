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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while (curr) {
                pq.push(curr);
                curr = curr->next;
            }
        }

        if (pq.empty()) return nullptr;

        ListNode* head = pq.top();
        pq.pop();
        ListNode* curr = head;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            node->next = nullptr;

            curr = curr->next;
        }

        return head;
    }
};