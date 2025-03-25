#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

void heapDelete(std::vector<int>& heap, const int& i);
void bubbleUp(std::vector<int>& heap, int i);
void maxHeapify(std::vector<int>& heap, int i);

inline int parent(int i) {
    if (i == 0)
        return -1;
    return (i - 1) / 2;
}

inline int left(int i) {
    return 2 * i + 1;
}

inline int right(int i) {
    return 2 * i + 2;
}

#endif