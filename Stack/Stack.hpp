#pragma once
#include "../Vector/Vector.hpp"
#include <iostream>

template <typename Type>

class Stack
{
   private:
    Vector<Type> data;

   public:
    // Push item to top of the stack
    // Time Complexity: O(1)
    void push(Type item) {
        data.append(item);
    }

    // Pop item from top of the stack
    // Time Complexity: O(1)
    Type pop() {
        assert(!isEmpty());
        Type item = data.remove(data.getSize() - 1);
        return item;
    }

    // Return item at top of stack without removing it from the stack
    // Time Complexity: O(1)
    const Type& peek() const {
        assert(!isEmpty());
        return data[data.getSize() - 1];
    }

    // Returns a true if stack is empty
    // Time Complexity: O(1)
    bool isEmpty() const {
        return data.getSize() == 0;
    }

    // Returns the amount of items in the stack
    // Time Complexity: O(1)
    size_t getSize() const {
        return data.getSize();
    }
};