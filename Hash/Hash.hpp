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

        // Method to resize the hash table to double the size
        void resize(){
            capacity *= 2;
            Vector<Pair<int, Type>> pairs = getAllPairs();
            auto oldBuckets = std::move(buckets);
            buckets.resize(capacity);
            for(const auto pair : pairs){
                put(pair.key, pair.value);
            }
        }

        // Method returns a copy of all pairs in Hash Table
        Vector<Pair<int,Type>> getAllPairs(){
            Vector<Pair<int, Type>> pairs;
            for(int i = 0; i < buckets.length(); i++){
                auto bucket = buckets[i];
                for(const auto pair : bucket){
                    pairs.append(pair);
                }
            }
            return pairs;
        }

        // Method returns a copy of all keys in Hash Table
        Vector<int> getAllKeys(){
            Vector<int> keys;
            for(int i = 0; i < buckets.length(); i++){
                auto bucket = buckets[i];
                for(const Pair<int, Type> pair : bucket){
                    keys.append(pair.key);
                }
            }
            return keys;
        }

        // Converts key to unsigned key // Basic hash function
        hashFunction(int key){
            return static_cast<size_t> key;
        }
    public:
        Hash() : capacity(INITIAL_CAPACITY), count(0){};
        
        // Adds key and item to hashmap
        void put(int key, Type item){
            int index = hashFunction(key) % capacity;
            auto& bucket = buckets[index];
            for(int i = 0; i < bucket.length(); i++){
                if(bucket[i].key == key){
                    bucket[i].value = item;
                    return;
                }
            }

            bucket.insert(Pair(key,item));
            count++;

            if ((float)count / capacity > 0.75) {
                resize();
            }
        }

        Type& operator[](const int key) const{
            int index = hashFunction(key);
            auto& bucket = buckets[index];
            for(int i = 0; i < bucket.length(); i++){
                if(bucket[i].key == key){
                    return bucket[i].value;
                }
            }
            assert(false);
        }   
};