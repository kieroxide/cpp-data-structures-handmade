#include "../Deque/Deque.hpp"
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
    size_t iterations = 10000000;

    std::string a = "Hello";
    Deque<std::string> dq;

    benchmark([&]() {dq.push_front(a);}, iterations); // 205ns

    benchmark([&]() {dq.front();}, iterations); // 11.5ns
    
    benchmark([&]() {dq.pop_front();}, iterations); // 157ns
    
    iterations = 9999;
    benchmark([&]() {dq.push_back(a);}, iterations); // 13us
    
    benchmark([&]() {dq.back();}, iterations); // 27us
    
    benchmark([&]() {dq.pop_back();}, iterations); // 12us

    return 0;
}