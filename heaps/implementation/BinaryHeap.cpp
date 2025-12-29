/*
 * Binary Heap Implementation (Min-Heap)
 *
 * Concepts:
 * - A complete binary tree represented as an array.
 * - Parent(i) = (i - 1) / 2
 * - LeftChild(i) = 2*i + 1
 * - RightChild(i) = 2*i + 2
 *
 * Time Complexities:
 * - Insert (Push): O(log N) - Sift Up
 * - Extract Min (Pop): O(log N) - Sift Down
 * - Get Min (Peek): O(1)
 * - Build Heap: O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    // Moves the element at index i up to its correct position (during insertion)
    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Moves the element at index i down to its correct position (during deletion and build)
    void siftDown(int i) {
        int minIndex = i;
        int l = left(i), r = right(i);
        int n = heap.size();

        if (l < n && heap[l] < heap[minIndex]) minIndex = l;
        if (r < n && heap[r] < heap[minIndex]) minIndex = r;

        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            siftDown(minIndex);
        }
    }

public:
    MinHeap() {}

    MinHeap(vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    void push(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) siftDown(0);
    }

    int top() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printHeap() {
        for (int i : heap) cout << i << " ";
        cout << endl;
    }
};

int main() {
    vector<int> data = {10, 20, 15, 30, 40};
    MinHeap h(data);

    h.push(5); // Sift Up causes 5 to become root

    cout << "Current Min: " << h.top() << endl; // 5

    h.pop(); // Remove 5, 10 returns to root

    cout << "New Min: " << h.top() << endl; // 10

    return 0;
}