/*
You are a film editor working on a classic movie being restored frame by frame. The film is represented as a long sequence 
of Frame objects linked together. The director has decided to replace a specific segment of the film with a brand-new, 
digitally remastered scene.
Your task is to cut out a portion of the main film reel and splice the new scene in its place.

You are given:
- mainReel: The head of the primary film sequence (a linked list).
- newScene: The head of the new scene to be inserted (another linked list).
- a: The index of the first frame to be removed from the mainReel.
- b: The index of the last frame to be removed from the mainReel.

You need to remove the frames from the a-th position to the b-th position (inclusive) in the mainReel and insert the entire 
newScene in their place. Return the head of the final, edited film reel.

Constraints:
3 <= mainReel.length <= 104
1 <= a <= b < mainReel.length - 1
1 <= newScene.length <= 104
*/

#include <iostream>
#include <vector>

// ------------------------------------------------------------------ //

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_linked_list(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void print_linked_list(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// ------------------------------------------------------------------ //

class Solution {
public:
    ListNode* replace(ListNode* mainReel, int a, int b, ListNode* newScene) {
        if (mainReel == nullptr && newScene == nullptr) return nullptr;

        int counter = 0;

        ListNode *itr1 = mainReel;
        ListNode *itr2 = newScene;

        while (itr1) {
            counter++;
            if (counter == a) break;
            itr1 = itr1->next;
        }
        counter--;

        ListNode *link1 = itr1;

        while (itr1) {
            if (counter == b) break;
            counter++;
            itr1 = itr1->next;
        }
        ListNode *link2 = itr1->next;

        link1->next = newScene;

        while (itr2->next) {
            itr2 = itr2->next;
        }

        itr2->next = link2;

        return mainReel;
    }
};

int main() {
    ListNode* mainReel = create_linked_list({10, 20, 30, 40, 50, 60});
    ListNode* newScene = create_linked_list({101, 102, 103});
    int a = 2, b = 4;

    std::cout << "Original List: ";
    print_linked_list(mainReel);

    Solution sol;
    ListNode* result_head = sol.replace(mainReel, a, b, newScene);

    std::cout << "Reordered List: ";
    print_linked_list(result_head);
    
    return 0;
}