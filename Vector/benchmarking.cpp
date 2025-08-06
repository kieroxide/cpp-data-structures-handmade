#include "../Vector/Vector.hpp"
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
    Vector<std::string> v;

    benchmark([&]() {v.append(a);}, iterations); // Append with reallocs 228ns
    v.clear();

    v.ensureCapacity(iterations);
    benchmark([&]() {v.append(a);}, iterations); // Append with reserved space 29ns

    iterations = 10000;
    v.resize(iterations);
    benchmark([&]() {v.remove(0);}, iterations); // Remove at worst case 247,843ns | 248us
    return 0;
}