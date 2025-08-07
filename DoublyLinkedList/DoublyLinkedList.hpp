#pragma once
#include <cassert>
#include <iostream>

template <typename Type>

class DoublyLinkedList
{
   private:
    struct Node
    {
        Type data;
        Node* next;
        Node* prev;
        Node(const Type& val) : data(val), next(nullptr), prev(nullptr) {
        }
    };
    Node* head;
    Node* tail;
    size_t size;

    // Helper method for inserting after a node
    // Time complexity: O(1)
    void insertAfter(Node* start, Node* inserted) {
        assert(start && inserted);
        Node* after = start->next;
        if(after){
            after->prev = inserted;
        }
        inserted->next = after;
        inserted->prev = start;
        start->next  = inserted;
    }

    // Helper method to traverse and return node at an index
    // Time complexity: O(n)
    Node* traverseTo(size_t index) const {
        assert(index < size);
        Node* current     = nullptr;
        // Traverses forwards or backwards depending on distance from head or tail
        if(index <= (size / 2)){
            size_t current_index = 0;
            current     = head;
            while (current_index != index) {
                current_index++;
                current = current->next;
            }
        } else {
            size_t current_index = size - 1;
            current     = tail;
            while (current_index != index) {
                current_index--;
                current = current->prev;
            }
        }
        return current;
    }

   public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {
    }
    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            insert(current->data); // insert at end
            current = current->next;
        }
    }
    // Deconstructor to free all allocated memory
    ~DoublyLinkedList() {
        clear();
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) {
        os << "[";
        for (size_t i = 0; i < list.getSize(); i++) {
            os << list[i];
            if (i < list.getSize() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Get and Sets list[index]
    // Time complexity: O(n)
    Type& operator[](size_t index) {
        Node* node = traverseTo(index);
        return node->data;
    }

    // Gets const list[index]
    // Time complexity: O(n)
    const Type& operator[](size_t index) const {
        Node* node = traverseTo(index);
        return node->data;
    }

    // Copy Assignment
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                insert(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Time complexity: O(1)
    size_t getSize() const {
        return size;
    }
    // Time complexity: O(1)
    bool isEmpty() const {
        return getSize() == 0;
    }

    // Method to insert at the end of list
    // Optionally returns pointer to added node
    // Time complexity: O(n)
    Node* insert(Type data) {
        return insert(data, size);
    }

    // Method to create and insert node at an index
    // Optionally returns pointer to added node
    // Time complexity: O(n)
    Node* insert(Type data, size_t index) {
        assert(index <= size);
        Node* node = new Node(data);
        if(size == 0){
            head = node;
            tail = node;
        }
        else if (index == 0) {
            Node* next = head;
            head       = node;
            head->next = next;
            if(next){
                next->prev = head;
            }
        }
        else if (index == size) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        else{
            Node* current = traverseTo(index - 1);
            insertAfter(current, node);
        }

        size++;
        return node;
    }

    // Method to remove node at an index
    // Time complexity: O(n)
    Type removeAt(size_t index) {
        assert(index < size);
        size--;

        if (index == 0) {
            Node* next    = head->next;
            if(next){
                next->prev = nullptr;
            }
            Node* oldHead = head;
            head          = next;
            Type value    = oldHead->data;
            delete oldHead;
            return value;
        }

        Node* prev = traverseTo(index - 1);
        // Links prev to next
        Node* node = prev->next;
        Node* next = node->next;
        prev->next = next;

        Type value = node->data;
        delete node;
        return value;
    }

    // Time complexity: O(1)
    void clear() {
        Node* current = head;
        while (current) { 
            Node* next = current->next;
            delete current;
            current = next;
        }
        size = 0;
        head = nullptr;
    }
};