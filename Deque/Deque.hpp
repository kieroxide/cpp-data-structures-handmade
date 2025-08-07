#pragma once
#include "../Linked-List/Linked-List.hpp"
#include <iostream>

template <typename Type>

class Deque
{
   private:
    LinkedList<Type> data;

   public:
    // Enqueue item to end of queue
    // Time complexity: O(n)
    void push_back(Type item) {
        data.insert(item, getSize());
    }

    // Time complexity: O(1)
    // Enqueue item to front of queue
    void push_front(Type item) {
        data.insert(item, 0);
    }

    // Time complexity: O(1)
    // Dequeue item at front of queue
    Type pop_front() {
        assert(!isEmpty());
        Type item = data.removeAt(0);
        return item;
    }

    // Dequeue item at back of queue
    // Time complexity: O(n)
    Type pop_back() {
        assert(!isEmpty());
        Type item = data.removeAt(getSize() - 1);
        return item;
    }

    // Return item at front of queue without dequeuing
    // Time complexity: O(1)
    Type& front() {
        assert(!isEmpty());
        return data[0];
    }

    // Return item at back of queue without dequeuing
    // Time complexity: O(n)
    Type& back() {
        assert(!isEmpty());
        return data[getSize() - 1];
    }

    // Returns a true if queue is empty
    // Time complexity: O(1)
    bool isEmpty() const {
        return data.getSize() == 0;
    }

    // Returns the amount of items in the queue
    // Time complexity: O(1)    
    int getSize() const {
        return data.getSize();
    }
};