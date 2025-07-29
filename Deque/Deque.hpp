#pragma once
#include "../Linked-List/Linked-List.hpp"

template<typename Type>

class Deque{
    private:
        LinkedList<Type> data;
        
    public:
        // Enqueue item to end of queue
        void push_back(Type item){
            data.insert(item, length());
        }

        // Enqueue item to front of queue
        void push_front(Type item){
            data.insert(item, 0);
        }
        
        // Dequeue item at front of queue
        Type pop_front(){
            assert(!isEmpty());
            Type item = data.removeAt(0);
            return item;
        }

        // Dequeue item at back of queue
        Type pop_back(){
            assert(!isEmpty());
            Type item = data.removeAt(length() - 1);
            return item;
        }

        // Return item at front of queue without dequeuing
        Type& front(){
            assert(!isEmpty());
            return data[0];
        }
        
        // Return item at back of queue without dequeuing
        Type& back(){
            assert(!isEmpty());
            return data[length() - 1];
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