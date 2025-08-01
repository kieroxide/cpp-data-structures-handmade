#include <cassert>
#include <iostream>
#include <string>

#include "Vector.hpp"

// Test append and operator[]
void testAppendAndAccess() {
    Vector<int> test;
    test.append(20);
    test.append(10);
    test.append(-1);

    assert(test[0] == 20 && test[1] == 10 && test[2] == -1);
    std::cout << "Append and access test passed.\n";
}

// Test dynamic resizing on append
void testDynamicResize() {
    Vector<int> test;
    for (int i = 0; i < 53; ++i) {
        test.append(i * 100);
    }
    assert(test.getSize() == 53);
    std::cout << "Dynamic resize test passed.\n";
}

// Test remove method and element shifting
void testRemove() {
    Vector<int> testB;
    testB.append(20);
    testB.append(10);
    testB.append(-1);
    testB.append(5);
    testB.append(6);
    testB.append(7);

    testB.remove(2); // remove -1
    testB.remove(1); // remove 10
    testB.remove(0); // remove 20

    assert(testB[0] == 5 && testB[1] == 6 && testB[2] == 7);
    std::cout << "Remove test passed.\n";
}

// Test search method
void testSearch() {
    Vector<std::string> testString;
    testString.append("Hello");
    testString.append("Yo");

    assert(testString.search("Yo"));
    assert(!testString.search("Nope"));

    std::cout << "Search test passed.\n";
}

// Test resize behavior and clear
void testResizeAndClear() {
    Vector<std::string> vec;
    vec.append("one");
    vec.append("two");
    vec.append("three");

    assert(vec.getSize() == 3);
    assert(vec[0] == "one");
    assert(vec[1] == "two");
    assert(vec[2] == "three");

    // Shrink resize to 2
    vec.resize(2);
    assert(vec.getSize() == 2);
    assert(vec[0] == "one");
    assert(vec[1] == "two");

    // Grow resize to 5 (capacity grows, size stays 2)
    vec.ensureCapacity(5);
    assert(vec.getCapacity() >= 5);
    assert(vec.getSize() == 2);

    vec.append("three");
    assert(vec[2] == "three");

    vec.clear();
    assert(vec.getSize() == 0);
    std::cout << "Resize and clear test passed.\n";
}

int main() {
    testAppendAndAccess();
    testDynamicResize();
    testRemove();
    testSearch();
    testResizeAndClear();

    std::cout << "All Vector tests passed successfully.\n";
    return 0;
}
