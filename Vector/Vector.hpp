#pragma once
#include <cassert>
#include <utility>
#include <iostream>

template <typename Type>

class Vector
{
   private:
    const int INITIAL_CAPACITY = 4;
    Type* data;
    int size;
    int capacity;

   public:
    // Default Constructor
    Vector() : data(new Type[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {
    }
    // Constructor with capacity
    Vector(int capacity) {
        assert(capacity > 0);
        data           = new Type[capacity];
        size           = 0;
        this->capacity = capacity;
    }
    // Move Constructor
    Vector(Vector&& other) noexcept {
        data     = other.data;
        size     = other.size;
        capacity = other.capacity;

        other.data     = nullptr;
        other.size     = 0;
        other.capacity = 0;
    }

    // Deconstructor: Deletes data on object destruction
    ~Vector() {
        delete[] data;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (int i = 0; i < vec.getSize(); i++) {
            os << vec[i];
            if (i < vec.getSize() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Move operator for std::Move()
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data     = other.data;
            size     = other.size;
            capacity = other.capacity;

            other.data     = nullptr;
            other.size     = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // get and set by index
    Type& operator[](int index) {
        assert(index >= 0 && index < size);
        return data[index];
    }

    // Const Get by index
    const Type& operator[](int index) const {
        assert(index >= 0 && index < size);
        return data[index];
    }

    // Returns current length
    int getSize() const {
        return size;
    }

    // Returns current capacity
    int getCapacity() const {
        return capacity;
    }

    // Method to add an item and resize if needed. Capacity doubles each resizing
    void append(const Type& item) {
        if (size >= capacity) {
            ensureCapacity(size + 1);
        }
        // appends the item and then increments the size
        data[size++] = item;
    }

    // Removes the item at the index and returns its value
    Type remove(int index) {
        assert(index < size && index >= 0);
        Type value = std::move(data[index]);
        // From index onwards shifts elements left
        for (int i = index; i < size - 1; i++) {
            data[i] = std::move(data[i + 1]);
        }
        size--;
        return value;
    }

    // Simple Search method to return if target is in Vector
    bool search(Type target) {
        for (int i = 0; i < size; i++) {
            if (data[i] == target) {
                return true;
            }
        }
        return false;
    }

    //Method to ensure there is enought capacity for the new size
    void ensureCapacity(int minCapacity){
        if (minCapacity <= 0) {
            minCapacity = 1;
        }
        // If new size is larger than capacity, allocate and copy to new array
        if (minCapacity > capacity) {
            int newCapacity = capacity;
            while(newCapacity < minCapacity){
                newCapacity *= 2;
            }
            capacity = newCapacity;

            Type* newData = new Type[capacity]();
            for (int i = 0; i < size; i++) {
                newData[i] = std::move(data[i]);
            }
            delete[] data;
            data     = newData;
        }
    }

    // Method to Manually resize the vector. If shrinking excess will be discarded
    // Clamped to minimum capacity of 1
    void resize(int newSize) {
        ensureCapacity(newSize);
        size = newSize;
    }

    // Method to clear the array to default
    void clear() {
        size = 0;
    }
};