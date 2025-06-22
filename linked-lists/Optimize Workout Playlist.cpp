/*
You're using a music app to create the perfect workout playlist. The playlist is structured as a sequence of 
songs, where each song points to the next one. To keep your energy levels high, you decide to try a new 
shuffling strategy: you want to swap the position of every two adjacent songs in the playlist.
For example, if your playlist is [Song A, Song B, Song C, Song D], you want to change it to [Song B, Song A, 
Song D, Song C].

You are given:
- head: The first Song object in your playlist, which is the head of a singly linked list. Each Song object 
has two properties:
- title (a string, like "Eye of the Tiger")
- next (a pointer to the next Song in the playlist, or null if it's the last song)

Reorganize the playlist by swapping every two adjacent songs. You must return the new first song of the modified 
playlist.

Input Playlist:
"Gonna Fly Now" -> "Thunderstruck" -> "Lose Yourself" -> "Till I Collapse"

Output Playlist:
"Thunderstruck" -> "Gonna Fly Now" -> "Till I Collapse" -> "Lose Yourself"

Constraint: You are only allowed to change the connections between songs (next pointers). You must not modify 
the title or any other data within the Song objects themselves.
*/

#include <iostream>
#include <vector>
#include <string>

// ------------------------------------------------------------------ //

struct ListNode {
    std::string val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(std::string x) : val(x), next(nullptr) {}
    ListNode(std::string x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_linked_list(const std::vector<std::string>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
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
    ListNode* swapSongs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        head = head->next;

        while (curr) {
            prev->next = curr->next;
            curr->next = prev;

            ListNode *save = prev->next;

            if (prev->next && prev->next->next)
                prev->next = prev->next->next;

            prev = save;
            if (prev == nullptr) break;

            curr = prev->next;
        }

        return head;
    }
};

int main() {
    std::vector<std::string> input = {
		"Gonna Fly Now",
		"Thunderstruck",
		"Lose Yourself",
		"Till I Collapse"
	};
    ListNode* head = create_linked_list(input);

    std::cout << "Original List: ";
    print_linked_list(head);

    Solution sol;
    ListNode* result_head = sol.swapSongs(head);

    std::cout << "Reordered List: ";
    print_linked_list(result_head);
    
    return 0;
}
