#include <cassert>
#include <iostream>
#include "DoublyLinkedList.hpp"

void testInsertAndSize() {
    DoublyLinkedList<int> list;
    assert(list.isEmpty());
    assert(list.getSize() == 0);

    list.insert(10);
    assert(!list.isEmpty());
    assert(list.getSize() == 1);
    assert(list[0] == 10);

    list.insert(20);
    list.insert(30);
    assert(list.getSize() == 3);
    assert(list[1] == 20);
    assert(list[2] == 30);
}

void testInsertAtIndex() {
    DoublyLinkedList<int> list;
    list.insert(10);
    list.insert(30);
    list.insert(20, 1); // Insert 20 at index 1

    assert(list.getSize() == 3);
    assert(list[0] == 10);
    assert(list[1] == 20);
    assert(list[2] == 30);

    list.insert(5, 0);  // Insert at head
    assert(list[0] == 5);
    assert(list.getSize() == 4);

    list.insert(40, 4); // Insert at tail (index = size)
    assert(list[4] == 40);
}

void testRemoveAt() {
    DoublyLinkedList<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    int val = list.removeAt(0);
    assert(val == 10);
    assert(list.getSize() == 3);
    assert(list[0] == 20);

    val = list.removeAt(1);
    assert(val == 30);
    assert(list.getSize() == 2);
    assert(list[1] == 40);

    val = list.removeAt(list.getSize() - 1);
    assert(val == 40);
    assert(list.getSize() == 1);

    val = list.removeAt(0);
    assert(val == 20);
    assert(list.isEmpty());
}

void testCopyConstructorAndAssignment() {
    DoublyLinkedList<int> list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    DoublyLinkedList<int> list2 = list1; // Copy constructor
    assert(list2.getSize() == 3);
    assert(list2[0] == 1 && list2[1] == 2 && list2[2] == 3);

    DoublyLinkedList<int> list3;
    list3 = list1; // Copy assignment
    assert(list3.getSize() == 3);
    assert(list3[0] == 1 && list3[1] == 2 && list3[2] == 3);
}

void testClear() {
    DoublyLinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    assert(list.getSize() == 3);

    list.clear();
    assert(list.isEmpty());
    assert(list.getSize() == 0);
}

int main() {
    testInsertAndSize();
    testInsertAtIndex();
    testRemoveAt();
    testCopyConstructorAndAssignment();
    testClear();

    std::cout << "All assertions passed.\n";
    return 0;
}
