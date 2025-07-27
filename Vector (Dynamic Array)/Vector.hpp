#include <cassert>

static const int INITIAL_CAPACITY = 4;
template<typename Type>

class Vector{
    private:
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
                    resized_data[i] = data[i];
                }
                delete[] data;
                data = resized_data;
            }
            //appends the item and then increments the length
            data[size++] = item;
        }
};