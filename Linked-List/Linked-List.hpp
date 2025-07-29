#pragma once
#include <cassert>
#include <iostream>

template<typename Type>

class LinkedList{
    private:
        struct Node {
            Type data;
            Node* next;
            Node(const Type& val) : data(val), next(nullptr) {}
        };
        Node* head;
        int size;

        // Helper method for inserting after a node
        void insertAfter(Node* start, Node* middle){
            assert(start && middle);

            Node* end = start->next;
            middle->next = end;
            start->next = middle;
        }

        // Helper method to traverse and return node at an index
        Node* traverseTo(int index) const{
            assert(index < size && index >= 0);

            int current_index = 0;
            Node* current = head;
            while(current_index != index && current->next != nullptr){
                current_index++;
                current = current->next;
            }
            return current;
        }

    public:
        LinkedList() : head(nullptr), size(0){}
        // Deconstructor to free all allocated memory
        ~LinkedList(){
            Node* current = head;
            while(current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        // Get and Sets list[index]
        Type& operator[](int index){
            Node* node = traverseTo(index);
            return node->data;
        }

        // Gets const list[index]
        const Type& operator[](int index) const{
            Node* node = traverseTo(index);
            return node->data;
        }

        int length() const{
            return size;
        }

        // Method to insert at the end of list
        void insert(Type data){
            insert(data, size);
        }

        // Method to create and insert node at an index
        void insert(Type data, int index){
            assert(index >= 0 && index <= size);
            size++;
            Node* node = new Node(data);

            if(index == 0){
                Node* next = head;
                head = node;
                head->next = next;
                return;
            }
            
            Node* current = traverseTo(index-1);
            insertAfter(current, node);
        }
        // Method to remove node at an index
        Type removeAt(int index){
            assert(index >= 0 && index < size);
            size--;

            if(index == 0){
                Node* next = head->next;
                Node* oldHead = head;
                head = next;
                Type value = oldHead->data;
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
};