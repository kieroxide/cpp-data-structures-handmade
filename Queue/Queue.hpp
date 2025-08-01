#pragma once
#include "../Deque/Deque.hpp"
#include <iostream>

template <typename Type>

class Queue
{
   private:
    Deque<Type> data;

   public:
    // Queue item to end of queue
    void enqueue(Type item) {
        data.push_back(item);
    }

    // Dequeue item at front of queue
    Type dequeue() {
        return data.pop_front();
    }

    // Return item at front of queue without dequeuing
    Type front() {
        return data.front();
    }

    // Returns a true if queue is empty
    bool isEmpty() const {
        return data.isEmpty();
    }

    // Returns the amount of items in the queue
    int getSize() const {
        return data.getSize();
    }
};