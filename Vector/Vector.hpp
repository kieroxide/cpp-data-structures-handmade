#pragma once
#include <cassert>
#include <utility>

template <typename Type>

class Vector
{
   private:
    const int INITIAL_CAPACITY = 4;
    Type* data;
    int size;
    int capacity;

   public:
    Vector() : data(new Type[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {
    }
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

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (int i = 0; i < vec.length(); i++) {
            os << vec[i];
            if (i < vec.length() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Deconstructor: Deletes data on object destruction
    ~Vector() {
        delete[] data;
    }

    int length() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
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

    // Method to add an item and resize if needed. Capacity doubles each resizing
    void append(const Type& item) {
        if (size >= capacity) {
            capacity *= 2;
            // Allocates new vector and copies values from old vector
            Type* resized_data = new Type[capacity];
            for (int i = 0; i < size; i++) {
                resized_data[i] = std::move(data[i]);
            }
            delete[] data;
            data = resized_data;
        }
        // appends the item and then increments the length
        data[size++] = item;
    }

    // Removes the item at the index and returns its value
    Type remove(int index) {
        Type value = std::move(data[index]);
        for (int i = index; i < size - 1; i++) {
            data[i] = std::move(data[i + 1]);
        }
        size--;
        data[size] = Type();
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

    // Method to Manually resize the vector. If shrinking excess will be discarded
    // Clamped to size of 1 if input is below 1
    void resize(int newSize) {
        if (newSize <= 0) {
            newSize = 1;
        }

        if (newSize > capacity) {
            Type* newData = new Type[newSize]();
            for (int i = 0; i < size; i++) {
                newData[i] = std::move(data[i]);
            }
            delete[] data;
            data     = newData;
            capacity = newSize;
        
        } else if (newSize > size) {
            for (int i = size; i < newSize; i++) {
                data[i] = Type();
            }
        }
        size = newSize;
    }

    // Method to clear the array to default
    void clear() {
        size = 0;
    }
};