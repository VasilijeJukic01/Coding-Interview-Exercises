/*
Imagine you're a part-time bookseller tasked with a specific organizational project. You have a single shelf of books that are 
in a disorganized order. The manager wants you to reorganize the shelf based on a specific publication year.
You are given the first Book on the shelf (the head of a linked list) and a pivotYear. Your task is to rearrange the books on 
the shelf such that all books published before the pivotYear come first, followed by all books published in or after the pivotYear.

Crucially, you must maintain the original relative order of the books within each of the two groups (the "older" books and the 
"newer" books).

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Constraints:
The number of books in the shelf is in the range [0, 200].
-200 <= pivot <= 200
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>

// ------------------------------------------------------------------ //

struct Book {
    std::string title;
    int publicationYear;
    Book *next;

    Book() : title(""), publicationYear(0), next(nullptr) {}
    Book(std::string t, int year) : title(t), publicationYear(year), next(nullptr) {}
    Book(std::string t, int year, Book *next) : title(t), publicationYear(year), next(next) {}
};

Book* create_shelf(const std::vector<std::pair<std::string, int>>& books_data) {
    if (books_data.empty()) {
        return nullptr;
    }
    Book* head = new Book(books_data[0].first, books_data[0].second);
    Book* current = head;
    for (size_t i = 1; i < books_data.size(); ++i) {
        current->next = new Book(books_data[i].first, books_data[i].second);
        current = current->next;
    }
    return head;
}

void print_shelf(Book* head) {
    Book* current = head;
    while (current != nullptr) {
        std::cout << "(\"" << current->title << "\", " << current->publicationYear << ") -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// ------------------------------------------------------------------ //

class Solution {
public:
    Book* reorganizeShelf(Book* head, int pivot) {
        if (head == nullptr || head->next == nullptr) return head;

        Book *less = new Book();
        Book *greater = new Book();

        Book *curr = head;

        Book *p = less;
        Book *q = greater;

        while (curr) {
            if (curr->publicationYear < pivot) {
                p->next = curr;
                p = p->next;
            }
            else {
                q->next = curr;
                q = q->next;
            }
            curr = curr->next;
        }

        q->next = nullptr;

        Book *tmp = greater;
        p->next = greater->next;
        delete tmp;

        tmp = less;
        head = less->next;
        delete tmp;

        return head;
    }
};

int main() {
    std::vector<std::pair<std::string, int>> input_books = {
        {"1984", 1984},
        {"The Stand", 1978},
        {"A Storm of Swords", 2000},
        {"The Da Vinci Code", 2003},
        {"Harry Potter", 1997},
        {"Project Hail Mary", 2021}
    };
    int pivotYear = 2000;
    
    Book* shelf_head = create_shelf(input_books);

    std::cout << "Original Shelf:" << std::endl;
    print_shelf(shelf_head);
    std::cout << "\nReorganizing with pivot year: " << pivotYear << std::endl;

    Solution sol;
    Book* result_head = sol.reorganizeShelf(shelf_head, pivotYear);

    std::cout << "\nReorganized Shelf:" << std::endl;
    print_shelf(result_head);
    
    return 0;
}