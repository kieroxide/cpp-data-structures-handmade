#include <cassert>

#include "Stack.hpp"


int main() {
    Stack<int> stack;

    // Initially empty
    assert(stack.isEmpty());
    assert(stack.getSize() == 0);

    // Push 1 element
    stack.push(10);
    assert(!stack.isEmpty());
    assert(stack.getSize() == 1);
    assert(stack.peek() == 10);  // peek does not remove

    // Push more elements
    stack.push(20);
    stack.push(30);
    assert(stack.getSize() == 3);
    assert(stack.peek() == 30);

    // Pop elements, check order
    assert(stack.pop() == 30);
    assert(stack.getSize() == 2);
    assert(stack.peek() == 20);

    assert(stack.pop() == 20);
    assert(stack.pop() == 10);

    // Now empty again
    assert(stack.isEmpty());

    // Uncomment to test (will terminate program)
    // stack.pop();
    // stack.peek();

    return 0;
}
