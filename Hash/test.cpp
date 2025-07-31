#include <iostream>
#include <string>

#include "../Hash/Hash.hpp"

int main() {
    Hash<int> hash;

    // Initial inserts - should fit without resizing (assuming initial capacity 4)
    hash.put(1, 10);
    hash.put(2, 20);
    hash.put(3, 30);
    hash.put(4, 40);

    // Validate retrieval before resize
    assert(hash[1] == 10);
    assert(hash[2] == 20);
    assert(hash[3] == 30);
    assert(hash[4] == 40);

    std::cout << "Hash before exceeding load factor:\n" << hash << "\n";

    // Insert one more to trigger resize (assuming load factor threshold 0.75)
    hash.put(5, 50);

    // Validate retrieval after resize
    assert(hash[1] == 10);
    assert(hash[2] == 20);
    assert(hash[3] == 30);
    assert(hash[4] == 40);
    assert(hash[5] == 50);

    std::cout << "Hash after exceeding load factor and resize:\n" << hash << "\n";

    std::cout << "All tests passed!\n";

    return 0;
}