#pragma once
#include "../Vector/Vector.hpp"

template<typename Type>

class Queue{
    private:
        Vector<Type> data;
        
    public:
        // Queue item to end of queue
        void enqueue(Type item){
            data.append(item);
        }

        // Dequeue item at front of queue
        Type dequeue(){
            assert(!isEmpty());
            Type item = data.remove(0);
            return item;
        }

        // Return item at front of queue without dequeuing
        Type front() const{
            assert(!isEmpty());
            return data[0];
        }
        
        // Returns a true if queue is empty
        bool isEmpty() const{
            return data.length() == 0;
        }
        
        // Returns the amount of items in the queue
        int length() const{
            return data.length();
        }
};