#pragma once
#include "../Vector/Vector.hpp"

template <typename Type>

class Stack
{
   private:
    Vector<Type> data;

   public:
    // Push item to top of the stack
    void push(Type item) {
        data.append(item);
    }

    // Pop item from top of the stack
    Type pop() {
        assert(!isEmpty());
        Type item = data.remove(data.getSize() - 1);
        return item;
    }

    // Return item at top of stack without removing it from the stack
    Type peek() const {
        assert(!isEmpty());
        return data[data.getSize() - 1];
    }

    // Returns a true if stack is empty
    bool isEmpty() const {
        return data.getSize() == 0;
    }

    // Returns the amount of items in the stack
    int getSize() const {
        return data.getSize();
    }
};