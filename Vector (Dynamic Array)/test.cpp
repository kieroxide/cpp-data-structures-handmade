#include <iostream>
#include "Vector.hpp"
#include <cassert>

int main(){
    Vector<int> test;

    test.append(20);
    test.append(10);
    test.append(-1);
    assert(test[0] == 20 && test[1] == 10 && test[2] == -1);
    std::cout << "vec[0] = " << test[0] << "\n"; // Expect 10
    std::cout << "vec[1] = " << test[1] << "\n"; // Expect 20
    std::cout << "vec[2] = " << test[2] << "\n"; // Expect 30

    // Test dynamic resizing
    for (int i = 0; i < 50; ++i) {
        test.append(i * 100);
    }

    assert(test.length() == 53);
    std::cout << "Length = " << test.length() << "\n"; 
}