#include <cassert>
#include <iostream>
#include "Pair.hpp"

int main() {
    Pair<int, std::string> p1; // default constructor
    p1.key = 10;
    p1.value = "hello";

    assert(p1.key == 10);
    assert(p1.value == "hello");

    Pair<int, std::string> p2(20, "world"); // parameterized constructor
    assert(p2.key == 20);
    assert(p2.value == "world");

    // Test assignment
    p1 = p2;
    assert(p1.key == 20);
    assert(p1.value == "world");

    std::cout << "All Pair tests passed.\n";
    return 0;
}