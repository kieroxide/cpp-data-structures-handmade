#pragma once
#include <cassert>
#include <iostream>

template <typename Type>

class LinkedList
{
   private:
    struct Node
    {
        Type data;
        Node* next;
        Node(const Type& val) : data(val), next(nullptr) {
        }
    };
    Node* head;
    size_t size;

    // Helper method for inserting after a node
    // Time complexity: O(1)
    void insertAfter(Node* start, Node* middle) {
        assert(start && middle);

        Node* end    = start->next;
        middle->next = end;
        start->next  = middle;
    }

    // Helper method to traverse and return node at an index
    // Time complexity: O(n)
    Node* traverseTo(size_t index) const {
        assert(index < size);
        size_t current_index = 0;
        Node* current     = head;
        while (current_index != index) {
            current_index++;
            current = current->next;
        }
        return current;
    }

   public:
    LinkedList() : head(nullptr), size(0) {
    }
    // Copy constructor
    LinkedList(const LinkedList& other) : head(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            insert(current->data); // insert at end
            current = current->next;
        }
    }
    // Deconstructor to free all allocated memory
    ~LinkedList() {
        clear();
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
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
    LinkedList& operator=(const LinkedList& other) {
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
        size++;
        Node* node = new Node(data);

        if (index == 0) {
            Node* next = head;
            head       = node;
            head->next = next;
            return head;
        }

        Node* current = traverseTo(index - 1);
        insertAfter(current, node);
        return node;
    }

    // Method to remove node at an index
    // Time complexity: O(n)
    Type removeAt(size_t index) {
        assert(index < size);
        size--;

        if (index == 0) {
            Node* next    = head->next;
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