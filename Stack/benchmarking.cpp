#include "../Stack/Stack.hpp"
#include <chrono>

template <typename Func>
void benchmark(const Func function, const size_t iterations = 10000){
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < iterations; i++){
        function();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto full_runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
    auto avg_runtime = static_cast<double>(full_runtime)/iterations;
    std::cout << "test function took " << avg_runtime << " nanoseconds\n";
}

int main(){
    size_t iterations = 9999999;

    std::string a = "Hello";
    std::string b = "World";
    Stack<std::string> v;

    benchmark([&]() {v.push(a);}, iterations); // push to stack 284.239 ns
    
    benchmark([&]() {v.peek();}, iterations); // peek stack 10ns

    benchmark([&]() {v.pop();}, iterations); // pop to stack 58ns
    return 0;
}