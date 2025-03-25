#include <cassert>
#include <iostream>
#include <vector>
#include "heap.hpp"

bool compareHeap(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

void printHeap(const std::vector<int>& h) {
    for (int val : h) std::cout << val << " ";
    std::cout << "\n";
}

void testHeapDelete() {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};
    heapDelete(heap, 1);
    std::vector<int> expected = {50, 38, 40, 10, 20, 35};
    assert(compareHeap(heap, expected));

    std::cout << "testHeapDelete passed!\n";
}

void testDeleteFirstElement() {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};
    heapDelete(heap, 0);
    std::vector<int> expected = { 40, 30, 38, 10, 20, 35 };
    assert(compareHeap(heap, expected));
    std::cout << "testDeleteFirstElement passed!\n";
}

void testDeleteLastElement() {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};
    heapDelete(heap, 6);
    std::vector<int> expected = {50, 30, 40, 10, 20, 35};
    assert(compareHeap(heap, expected));
    std::cout << "testDeleteLastElement passed!\n";
}

void testDeleteOutOfBounds() {
    std::vector<int> heap = {50, 30, 40};
    heapDelete(heap, -1); // should do nothing
    heapDelete(heap, 3);  // should do nothing
    std::vector<int> expected = {50, 30, 40};
    assert(compareHeap(heap, expected));
    std::cout << "testDeleteOutOfBounds passed!\n";
}

void testDeleteTriggersIncreaseKey() {
    std::vector<int> heap = {55, 20, 40, 10, 5, 35, 38};
    heap[1] = 3; // simulate manually breaking the heap property upward
    heapDelete(heap, 4); // remove a leaf node, heap should restore
    std::vector<int> expected = {55, 38, 40, 10, 3, 35};
    assert(compareHeap(heap, expected));
    std::cout << "testDeleteTriggersIncreaseKey passed!\n";
}

void testDeleteSingleElement() {
    std::vector<int> heap = {42};
    heapDelete(heap, 0);
    std::vector<int> expected = {};
    assert(compareHeap(heap, expected));
    std::cout << "testDeleteSingleElement passed!\n";
}

void testDeleteEmptyHeap() {
    std::vector<int> heap = {};
    heapDelete(heap, 0);
    std::vector<int> expected = {};
    assert(compareHeap(heap, expected));
    std::cout << "testDeleteEmptyHeap passed!\n";
}

int main() {
    testHeapDelete();
    testDeleteFirstElement();
    testDeleteLastElement();
    testDeleteOutOfBounds();
    testDeleteTriggersIncreaseKey();
    testDeleteSingleElement();
    testDeleteEmptyHeap();

    std::cout << "All tests passed!\n";
    return 0;
}

