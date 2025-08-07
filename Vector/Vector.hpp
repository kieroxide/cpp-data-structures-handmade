#pragma once
#include <cassert>
#include <iostream>
#include <utility>


template <typename Type>

class Vector
{
   private:
    const size_t INITIAL_CAPACITY = 4;
    Type* data;
    size_t size;
    size_t capacity;

   public:
    // Default Constructor
    //[Time Complexity = O(1)]
    Vector() : data(new Type[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {
    }
    // Constructor with capacity
    //[Time Complexity = O(1)]
    Vector(size_t capacity) {
        this->capacity = (capacity == 0 ? 1 : capacity);
        data           = new Type[this->capacity];
        size           = 0;
    }

    // Move Constructor
    //[Time Complexity = O(1)]
    Vector(Vector&& other) noexcept {
        data     = other.data;
        size     = other.size;
        capacity = other.capacity;

        other.data     = nullptr;
        other.size     = 0;
        other.capacity = 0;
    }

    // Copy Constructor
    //[Time Complexity = O(n)]
    Vector(const Vector& other) {
        data     = new Type[other.capacity];
        size     = other.size;
        capacity = other.capacity;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Deconstructor: Deletes data on object destruction
    ~Vector() {
        delete[] data;
    }

    // Output operator
    //[Time Complexity = O(n)]
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (size_t i = 0; i < vec.getSize(); i++) {
            os << vec[i];
            if (i < vec.getSize() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Move operator for std::Move()
    //[Time Complexity = O(1)]
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

    // Copy operator
    //[Time Complexity = O(n)]
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            data     = new Type[other.capacity];
            size     = other.size;
            capacity = other.capacity;
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // get and set by index
    //[Time Complexity = O(1)]
    Type& operator[](size_t index) {
        assert(index < size);
        return data[index];
    }

    // Const Get by index
    //[Time Complexity = O(1)]
    const Type& operator[](size_t index) const {
        assert(index < size);
        return data[index];
    }

    // Returns current length
    //[Time Complexity = O(1)]
    size_t getSize() const {
        return size;
    }

    // Returns current capacity
    //[Time Complexity = O(1)]
    size_t getCapacity() const {
        return capacity;
    }

    // Method to add an item and resize if needed. Capacity doubles each resizing
    //[Time Complexity = O(n), amortized = O(1)]
    void append(const Type& item) {
        if (size >= capacity) {
            ensureCapacity(size + 1);
        }
        // appends the item and then increments the size
        data[size++] = item;
    }

    // Removes the item at the index and returns its value
    // [Time Complexity = O(n)]
    Type remove(size_t index) {
        assert(index < size);
        Type value = std::move(data[index]);
        // From index onwards shifts elements left
        for (size_t i = index; i < size - 1; i++) {
            data[i] = std::move(data[i + 1]);
        }
        size--;
        return value;
    }

    // Simple Search method to return if target is in Vector
    //[Time Complexity = O(n)]
    bool search(const Type& target) const {
        for (size_t i = 0; i < size; i++) {
            if (data[i] == target) {
                return true;
            }
        }
        return false;
    }

    // Method to ensure there is enought capacity for the new size
    //[Time Complexity = O(n)]
    void ensureCapacity(size_t minCapacity) {
        if (minCapacity == 0) {
            minCapacity = 1;
        }
        // If new size is larger than capacity, allocate and copy to new array
        if (minCapacity > capacity) {
            size_t newCapacity = capacity;
            while (newCapacity < minCapacity) {
                newCapacity *= 2;
            }
            capacity = newCapacity;

            Type* newData = new Type[capacity];
            for (size_t i = 0; i < size; i++) {
                newData[i] = std::move(data[i]);
            }
            delete[] data;
            data = newData;
        }
    }

    // Method to Manually resize the vector. If shrinking excess will be discarded
    // Clamped to minimum capacity of 1
    //[Time Complexity = O(n)]
    void resize(size_t newSize) {
        ensureCapacity(newSize);
        if (newSize > size) {
            for (size_t i = size; i < newSize; ++i) {
                data[i] = Type();  // default-construct new elements
            }
        }
        size = newSize;
    }

    // Method to clear the array to default
    //[Time Complexity = O(1)]
    void clear() {
        size = 0;
    }
};