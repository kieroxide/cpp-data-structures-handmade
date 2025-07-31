#include <cassert>
#include "../Linked-List/Linked-List.hpp"
#include "../Pair/Pair.hpp"
#include "../Vector/Vector.hpp"

template<typename Type>

class Hash{
    private:
        const int INITIAL_CAPACITY = 4; 
        Vector<LinkedList<Pair<int, Type>>> buckets;
        int capacity;
        int count;

        void resize(){
            
        }
    public:
        Hash() : capacity(INITIAL_CAPACITY), count(0){};

        hashFunction(int key){
            return static_cast<size_t> key;
        }

        void put(int key, Type value){
            int index = hashFunction(key) % capacity;
            LinkedList<Pair<int, Type>>& bucket = buckets[index];
            for(int i = 0; i < bucket.length(); i++){
                if(bucket[i].key == key){
                    bucket[i].value = value;
                    return;
                }
            }

            bucket.insert(Pair(key,value));
            count++;

            if ((float)count / capacity > 0.75) {
                resize();
            }
        }
};