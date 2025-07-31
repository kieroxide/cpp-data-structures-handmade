#include <cassert>
#include <iostream>

#include "Linked-List.hpp"

int main() {
    LinkedList<int> test;

    // Insert tests
    int size = 4;
    for (int i = 0; i < size; i++) {
        test.insert(i);
        assert(test[i] == i);
    }

    test.insert(10, test.length());
    assert(test[test.length() - 1] == 10);

    test.insert(-1, 0);
    test.insert(-2, 2);
    assert(test.length() == 7);
    assert(test[0] == -1 && test[2] == -2);
    // ALL INSERTION TEST PASSED

    // Assignment tests
    test[0]                 = 100;
    test[test.length() - 1] = 5;
    assert(test[0] == 100 && test[test.length() - 1] == 5);
    // ASSIGNMENT TESTS PASSED

    // Remove Tests
    test[1] = 5;
    test.removeAt(0);
    assert(test[0] == 5);

    test[test.length() - 2] = 25;
    test.removeAt(test.length() - 1);
    assert(test[test.length() - 1] == 25);
    assert(test.length() == 5);

    for (int i = 0; i < test.length(); i++) {
        std::cout << "test[" << i << "]: " << test[i] << std::endl;
    }
    // REMOVE TESTS PASSED
}