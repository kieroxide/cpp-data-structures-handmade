#include <cassert>

#include "Queue.hpp"


int main() {
    Queue<int> q;

    // Initially empty
    assert(q.isEmpty());
    assert(q.length() == 0);

    // Enqueue one item
    q.enqueue(42);
    assert(!q.isEmpty());
    assert(q.length() == 1);
    assert(q.front() == 42);

    // Enqueue more items
    q.enqueue(100);
    q.enqueue(200);
    assert(q.length() == 3);
    assert(q.front() == 42);  // Front should still be first item

    // Dequeue items and check order
    assert(q.dequeue() == 42);
    assert(q.length() == 2);
    assert(q.front() == 100);

    assert(q.dequeue() == 100);
    assert(q.dequeue() == 200);

    // Queue should be empty now
    assert(q.isEmpty());
    assert(q.length() == 0);

    // Uncommenting these should cause assert failure:
    // q.dequeue();
    // q.front();

    return 0;
}
