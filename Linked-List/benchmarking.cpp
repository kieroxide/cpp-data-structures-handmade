#include "../Linked-List/Linked-List.hpp"
#include <chrono>

template <typename Func>
void benchmark(const Func function, const size_t iterations = 10000){
    auto t1 = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i < iterations; i++){
        function();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto full_runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
    auto avg_runtime = static_cast<double>(full_runtime)/iterations;
    std::cout << "test function took " << avg_runtime << " nanoseconds\n";
}

int main(){
    size_t iterations = 100000;

    std::string a = "Hello";
    LinkedList<std::string> ll;

    benchmark([&]() {ll.insert(a, 0);}, iterations); // 76ns
    
    benchmark([&]() {ll.removeAt(0);}, iterations); // 237ns
    
    benchmark([&]() {ll.insert(a);}, iterations); // 149us
    
    benchmark([&]() {ll.removeAt(ll.getSize() - 1);}, iterations); // 146us

    return 0;
}