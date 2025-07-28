#pragma once
#include <cassert>
#include <utility>

template<typename Type>

class Vector{
    private:
        const int INITIAL_CAPACITY = 4; 
        Type* data;
        int size;
        int capacity;
    public:
        Vector() : data(new Type[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {}
        
        // Deconstructor: Deletes data on object destruction
        ~Vector() {
            delete[] data;
        }

        int length() const{
            return size;
        }

        //get and set by index
        Type& operator[](int index){
            assert(index >= 0 && index < size);
            return data[index];
        }

        // Method to add an item and resize if needed. Capacity doubles each resizing
        void append(const Type& item){
            if(size >= capacity){
                capacity *= 2;
                // Allocates new array and copies values from old array
                Type* resized_data = new Type[capacity];
                for(int i = 0; i < size; i++){ 
                    resized_data[i] = std::move(data[i]);
                }
                delete[] data;
                data = resized_data;
            }
            //appends the item and then increments the length
            data[size++] = item;
        }

        //Removes the item at the index and returns its value
        Type remove(int index){
            Type value = std::move(data[index]);
            for(int i = index; i < size - 1; i++){
                data[i] = std::move(data[i+1]);
            }
            size--;
            data[size] = Type();
            return value;
        }
        
        // Simple Search method to return if target is in Vector
        bool search(Type target){
            for(int i = 0; i < size; i++){
                if(data[i] == target){
                    return true;
                }
            }
            return false;
        }
};