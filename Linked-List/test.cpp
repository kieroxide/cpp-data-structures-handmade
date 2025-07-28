#include "Linked-List.hpp"

#include <iostream>
#include <cassert>

int main(){
    LinkedList<int> test;

    // Insert tests

    int size = 4;
    for(int i = 0; i < size; i++){ 
        test.insert(i);
        assert(test[i] == i);
    }
    
    test.insert(10, test.length());
    assert(test[test.length() - 1] == 10);

    test.insert(-1, 0);
    test.insert(-2, 2);
    assert(test.length() == 7);
    assert(test[0] == -1 && test[2] == -2);

    //ALL INSERTION TEST PASSED
    
    test[0] = 100;
    test[test.length() - 1] = 5;
    assert(test[0] == 100 && test[test.length() - 1] == 5);
    for(int i = 0; i < test.length(); i++){
        std::cout << "test[" << i << "]: " << test[i] << std::endl;
    }
    
    // ASSIGNMENT TESTS PASSED
}