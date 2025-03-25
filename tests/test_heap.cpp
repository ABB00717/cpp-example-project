#include <gtest/gtest.h>
#include <cassert>
#include <iostream>
#include <vector>
#include "heap.hpp"

bool compareHeap(const std::vector<int>& a, const std::vector<int>& b) {
    return a == b;
}

TEST(HeapTest, DeleteMiddle) {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};
    heapDelete(heap, 1);
    std::vector<int> expected = {50, 38, 40, 10, 20, 35};
    EXPECT_TRUE(compareHeap(heap, expected));
}

TEST(HeapTest, DeleteFirstElement) {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};
    heapDelete(heap, 0);
    std::vector<int> expected = {40, 30, 38, 10, 20, 35};
    EXPECT_TRUE(compareHeap(heap, expected));
}

TEST(HeapTest, DeleteLastElement) {
    std::vector<int> heap = {50, 30, 40, 10, 20, 35, 38};
    heapDelete(heap, 6);
    std::vector<int> expected = {50, 30, 40, 10, 20, 35};
    EXPECT_TRUE(compareHeap(heap, expected));
}

TEST(HeapTest, DeleteOutOfBounds) {
    std::vector<int> heap = {50, 30, 40};
    // Should do nothing
    heapDelete(heap, -1);
    heapDelete(heap, 3);
    std::vector<int> expected = {50, 30, 40};
    EXPECT_TRUE(compareHeap(heap, expected));
}

TEST(HeapTest, DeleteTriggersIncreaseKey) {
    std::vector<int> heap = {55, 20, 40, 10, 5, 35, 38};
    heap[1] = 3; // simulate break
    heapDelete(heap, 4); // remove a leaf node, heap should restore
    std::vector<int> expected = {55, 38, 40, 10, 3, 35};
    EXPECT_TRUE(compareHeap(heap, expected));
}

TEST(HeapTest, DeleteSingleElement) {
    std::vector<int> heap = {42};
    heapDelete(heap, 0);
    std::vector<int> expected = {};
    EXPECT_TRUE(compareHeap(heap, expected));
}

TEST(HeapTest, DeleteEmptyHeap) {
    std::vector<int> heap = {};
    heapDelete(heap, 0);
    std::vector<int> expected = {};
    EXPECT_TRUE(compareHeap(heap, expected));
}

// Google Test main entry
int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

