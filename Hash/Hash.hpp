#include <cassert>
#include <iostream>

#include "../Linked-List/Linked-List.hpp"
#include "../Pair/Pair.hpp"
#include "../Vector/Vector.hpp"

template <typename Type>

class Hash
{
   private:
    const int INITIAL_CAPACITY = 4;
    Vector<LinkedList<Pair<int, Type>>> buckets;
    int count;

    // Method to resize the hash table to double the size
    void resize() {
        auto pairs      = getAllPairs();
        int oldCapacity = buckets.getCapacity();
        buckets.clear();
        buckets.resize(oldCapacity * 2);
        count = 0;
        for (int i = 0; i < pairs.length(); i++) {
            put(pairs[i].key, pairs[i].value);
        }
    }

    // Method returns a copy of all pairs in Hash Table
    Vector<Pair<int, Type>> getAllPairs() {
        Vector<Pair<int, Type>> pairs;
        for (int i = 0; i < buckets.length(); i++) {
            auto bucket = buckets[i];
            for (int k = 0; k < bucket.length(); k++) {
                pairs.append(bucket[k]);
            }
        }
        return pairs;
    }

    // Method returns a copy of all keys in Hash Table
    Vector<int> getAllKeys() {
        Vector<int> keys;
        for (int i = 0; i < buckets.length(); i++) {
            auto bucket = buckets[i];
            for (int k = 0; k < bucket.length(); k++) {
                keys.append(bucket[k].key);
            }
        }
        return keys;
    }

    // Converts key to unsigned key // Basic hash function
    size_t hashFunction(int key) const {
        return static_cast<size_t>(key < 0 ? -key : key);
    }

   public:
    Hash() : buckets(INITIAL_CAPACITY), count(0) {
        buckets.resize(INITIAL_CAPACITY);
    };

    friend std::ostream& operator<<(std::ostream& os, const Hash& hash) {
        os << "[";
        for (int i = 0; i < hash.buckets.length(); i++) {
            os << hash.buckets[i];
            if (i < hash.buckets.length() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Adds key and value to hashmap
    void put(int key, Type value) {
        int index    = hashFunction(key) % buckets.getCapacity();
        auto& bucket = buckets[index];
        for (int i = 0; i < bucket.length(); i++) {
            if (bucket[i].key == key) {
                bucket[i].value = value;
                return;
            }
        }
        bucket.insert(Pair<int, Type>(key, value));
        float loadFactor = static_cast<float>(count) / buckets.getCapacity();

        if (loadFactor > 0.75f) {
            resize();
        }
        count++;
    }

    // Get and Set method using []
    Type& operator[](const int key) {
        int index    = hashFunction(key) % buckets.getCapacity();
        auto& bucket = buckets[index];
        for (int i = 0; i < bucket.length(); i++) {
            if (bucket[i].key == key) {
                return bucket[i].value;
            }
        }
        // if not found inserts it
        put(key, Type());
        auto& newBucket = buckets[hashFunction(key) % buckets.getCapacity()];
        for (int i = 0; i < newBucket.length(); i++) {
            if (newBucket[i].key == key) {
                return newBucket[i].value;
            }
        }
    }
};