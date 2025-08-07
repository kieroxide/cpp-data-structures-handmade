#include "../Hash/Hash.hpp"
#include "../Linked-List/Linked-List.hpp"

template <typename Type>

class MapLink
{
   private:
    using Node    = typename LinkedList<Type>::Node;
    using NodePtr = typename Node*;
    Hash<NodePtr> indexToNode;
    LinkedList<Type> list;
    size_t size;

   public:
    MapLink() : size(0) {
    }

    void insert(const Type& value) {
        insert(value, size);
    }

    void insert(const Type& value, int index) {
        assert(index <= size);
        if (size == 0) {
            NodePtr ptr = list.insert(value);
            indexToNode.put(index, ptr);
            size++;
            return;
        }
        NodePtr ptr  = indexToNode[index - 1];
        NodePtr node = new Node(value);
        list.insertAfter(ptr, node);
        size++;
        return;
    }

    void remove(int index) {
    }

    Type* get(int index) {
    }
};
