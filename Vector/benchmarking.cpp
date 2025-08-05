#include "../Vector/Vector.hpp"
#include <chrono>

template <typename Func>
void benchmark(Func function, uint32_t iterations = 10000){
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
    uint32_t iterations = 10000000;

    std::string a = "Hello";
    std::string b = "World";
    Vector<std::string> v;

    benchmark([&]() {v.append(a);}, iterations); // Append with reallocs 228ns
    v.clear();

    v.ensureCapacity(10000000);
    benchmark([&]() {v.append(a);}, iterations); // Append with reserved space 29ns

    return 0;
}