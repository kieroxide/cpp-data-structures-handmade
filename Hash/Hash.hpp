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
        // Gets all key-value pairs
        auto pairs      = getAllPairs();
        int oldCapacity = buckets.getCapacity();

        // Clear and resize buckets array
        buckets.clear();
        buckets.resize(oldCapacity * 2);
        count = 0;

        // Recalculate index's for each pair
        for (int i = 0; i < pairs.getSize(); i++) {
            put(pairs[i].key, pairs[i].value);
        }
    }

    // Method returns a copy of all pairs in Hash Table
    Vector<Pair<int, Type>> getAllPairs() {
        Vector<Pair<int, Type>> pairs;
        for (int i = 0; i < buckets.getSize(); i++) {
            auto bucket = buckets[i];
            for (int k = 0; k < bucket.getSize(); k++) {
                pairs.append(bucket[k]);
            }
        }
        return pairs;
    }

    // Method returns a copy of all keys in Hash Table
    Vector<int> getAllKeys() {
        Vector<int> keys;
        for (int i = 0; i < buckets.getSize(); i++) {
            auto bucket = buckets[i];
            for (int k = 0; k < bucket.getSize(); k++) {
                keys.append(bucket[k].key);
            }
        }
        return keys;
    }

    // Converts key to unsigned key // Basic hash function
    size_t hashFunction(int key) const {
        return static_cast<size_t>(key < 0 ? -key : key);
    }

    // Converts key to Hashmap index
    size_t calculateIndex(const int key) const{
        return hashFunction(key) % buckets.getCapacity();
    }

   public:
    Hash() : buckets(INITIAL_CAPACITY), count(0) {
        buckets.resize(INITIAL_CAPACITY);
    };

    friend std::ostream& operator<<(std::ostream& os, const Hash& hash) {
        os << "[";
        for (int i = 0; i < hash.buckets.getSize(); i++) {
            os << hash.buckets[i];
            if (i < hash.buckets.getSize() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Returns total amount of key-value pairs in hashmap
    int getSize() const{
        return count;
    }

    // Returns true if hashmap is empty
    bool isEmpty() const{
        return count == 0;
    }

    // Adds key and value to hashmap
    void put(int key, Type value) {
        // Locates key's index
        int index        = calculateIndex(key);
        auto& bucket     = buckets[index];
        int bucket_index = containedAt(key, bucket);

        // If found update to new value
        if (bucket_index >= 0) {
            bucket[bucket_index].value = value;
            return;
        } else {
            bucket.insert(Pair<int, Type>(key, value));
            count++;
        }

        // Resize if ratio limit of count to capacity is exceeded
        float loadFactor = static_cast<float>(count) / buckets.getCapacity();
        if (loadFactor > 0.75f) {
            resize();
        }
    }

    // Removes element with inputted key returns true if found
    bool remove(int key) {
        int index        = calculateIndex(key);
        auto& bucket     = buckets[index];
        int bucket_index = containedAt(key, bucket);
        // If key found remove key and value
        if (bucket_index >= 0) {
            bucket.remove(bucket_index);
            count--;
            return true;
        }
        return false;
    }

    // Returns boolean whether hashmap contains a value for a key
    bool contains(const int key) const{
        int index        = calculateIndex(key);
        auto& bucket     = buckets[index];
        return containedAt(key, bucket) >= 0;
    }

    // Returns the index at which a key is located in a bucket. Else returns -1
    int containedAt(const int key, const LinkedList<Pair<int, Type>>& bucket) const {
        for (int i = 0; i < bucket.getSize(); i++) {
            if (bucket[i].key == key) {
                return i;
            }
        }
        return -1;
    }

    // Get and Set method using []
    Type& operator[](const int key) {
        int index        = calculateIndex(key);
        auto& bucket     = buckets[index];
        int bucket_index = containedAt(key, bucket);

        if (bucket_index >= 0) {
            return bucket[bucket_index].value;
        }

        // if not found inserts it
        put(key, Type());
        auto& newBucket = buckets[calculateIndex(key)];  // Recalcuate index in case of resizing
        bucket_index    = containedAt(key, newBucket);
        return newBucket[bucket_index].value;
    }
};