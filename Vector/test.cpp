#include <cassert>
#include <iostream>
#include <string>

#include "Vector.hpp"


int main() {
    Vector<int> test;

    // Append Testing
    test.append(20);
    test.append(10);
    test.append(-1);

    assert(test[0] == 20 && test[1] == 10 && test[2] == -1);

    std::cout << "vec[0] = " << test[0] << "\n";  // Expect 20
    std::cout << "vec[1] = " << test[1] << "\n";  // Expect 10
    std::cout << "vec[2] = " << test[2] << "\n";  // Expect -1
    // Append Testing passed

    // Test dynamic resizing
    for (int i = 0; i < 50; ++i) {
        test.append(i * 100);
    }

    assert(test.length() == 53);
    std::cout << "Length = " << test.length() << "\n";
    // Dynamic resizing passed

    // Remove Testing
    Vector<int> testB;
    testB.append(20);
    testB.append(10);
    testB.append(-1);

    testB.append(5);
    testB.append(6);
    testB.append(7);

    testB.remove(2);
    testB.remove(1);
    testB.remove(0);
    assert(testB[0] == 5 && testB[1] == 6 && testB[2] == 7);

    // Remove Testing passed

    // Search Testing
    Vector<std::string> testString;
    testString.append(std::string("Hello"));
    testString.append(std::string("Yo"));

    bool found = testString.search(std::string("Yo"));
    std::cout << "Found 'Yo'? " << (found ? "Yes" : "No") << std::endl;
    assert(found);

    bool notFound = testString.search(std::string("Nope"));
    assert(!notFound);
    std::cout << "Found 'Nope'? " << (notFound ? "Yes" : "No") << std::endl;
    // Search Testing Passed

    // Resizing Test
    Vector<std::string> vec;

    vec.append("one");
    vec.append("two");
    vec.append("three");

    assert(vec.length() == 3);
    assert(vec[0] == "one");
    assert(vec[1] == "two");
    assert(vec[2] == "three");

    // Shrink resize to 2 (drops last element)
    vec.resize(2);
    assert(vec.length() == 2);
    assert(vec[0] == "one");
    assert(vec[1] == "two");

    // Grow resize to 5 (capacity grows, size stays at 2)
    vec.resize(5);
    assert(vec.length() == 2);
    vec.append("three");
    assert(vec[0] == "one");
    assert(vec[1] == "two");
    assert(vec[2] == "three");

    vec.clear();
    assert(vec.length() == 0);
    return 0;
}