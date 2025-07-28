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

        void insertAfter(Node* start, Node* middle){
            assert(start && middle);

            Node* end = start->next;
            middle->next = end;
            start->next = middle;
        }
        Node* traverseTo(int index){
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
        ~LinkedList(){
            Node* current = head;
            while(current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        Type& operator[](int index){
            Node* node = traverseTo(index);
            return node->data;
        }
        int length(){
            return size;
        }

        void insert(Type data){
            insert(data, size);
        }
        void insert(Type data, int index){
            assert(index >= 0 && index <= size);
            Node* node = new Node(data);
            size++;
            if(index == 0){
                Node* next = head;
                head = node;
                head->next = next;
                return;
            }
            Node* current = traverseTo(index-1);
            insertAfter(current, node);
        }
};