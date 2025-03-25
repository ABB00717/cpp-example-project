#include <iostream>
#include <vector>
#include "../include/heap.hpp"

int main() {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};

    std::cout << "Before delete:\n";
    for (int val : heap)
        std::cout << val << " ";
    std::cout << "\n";

    heapDelete(heap, 1);  // delete index 1 (30）

    std::cout << "After delete:\n";
    for (int val : heap)
        std::cout << val << " ";
    std::cout << "\n";

    return 0;
}