#include <cassert>
#include "Deque.hpp"

int main() {
    Deque<int> dq;

    assert(dq.isEmpty());
    assert(dq.length() == 0);

    // Push front and back
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    assert(!dq.isEmpty());
    assert(dq.length() == 3);

    // Check front and back
    assert(dq.front() == 20);
    assert(dq.back() == 30);

    // Pop front and check values
    int val = dq.pop_front();
    assert(val == 20);
    assert(dq.front() == 10);
    assert(dq.length() == 2);

    // Pop back and check values
    val = dq.pop_back();
    assert(val == 30);
    assert(dq.back() == 10);
    assert(dq.length() == 1);

    // Pop last element
    val = dq.pop_front();
    assert(val == 10);
    assert(dq.isEmpty());
    assert(dq.length() == 0);

    // Test pushing after emptying
    dq.push_front(5);
    assert(dq.front() == 5);
    assert(dq.back() == 5);
    assert(dq.length() == 1);

    return 0;
}
