#include <iostream>
#include "Vector.hpp"
#include <cassert>
#include <string>

int main(){
    Vector<int> test;

    // Append Testing
    test.append(20);
    test.append(10);
    test.append(-1);

    assert(test[0] == 20 && test[1] == 10 && test[2] == -1);

    std::cout << "vec[0] = " << test[0] << "\n"; // Expect 10
    std::cout << "vec[1] = " << test[1] << "\n"; // Expect 20
    std::cout << "vec[2] = " << test[2] << "\n"; // Expect 30
    // Append Testing passed

    // Test dynamic resizing
    for (int i = 0; i < 50; ++i) {
        test.append(i * 100);
    }

    assert(test.length() == 53);
    std::cout << "Length = " << test.length() << "\n"; 
    // Dynamic resizing passed

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
    // Testing Passed
    return 0;
}