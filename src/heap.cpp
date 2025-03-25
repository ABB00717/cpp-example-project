#include "../include/heap.hpp"

void heapDelete(std::vector<int>& A, const int& i) {
    if (i < 0 || i >= A.size()) {
        return;
    }

    A[i] = A.back();  // Replace the delete node with the last node
    A.pop_back();     // Delete the last node

    if (i > 0 && A[i] > A[parent(i)]) {
        bubbleUp(A, i);  // Restore max-heap property upwards
    } else {
        maxHeapify(A, i);  // Restore max-heap property downwards
    }
}

void bubbleUp(std::vector<int>& A, int i) {
    while (i > 0 && A[i] > A[parent(i)]) {
        std::swap(A[i], A[parent(i)]);
        i = parent(i);
    }
}

void maxHeapify(std::vector<int>& heap, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap.size() && heap[l] > heap[largest]) {
        largest = l;
    }

    if (r < heap.size() && heap[r] > heap[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        maxHeapify(heap, largest);
    }
}
