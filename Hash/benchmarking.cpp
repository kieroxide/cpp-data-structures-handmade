#include "../Hash/Hash.hpp"
#include <chrono>
#include <iostream>

template <typename Func>
void benchmark(const Func& function, size_t iterations = 10000) {
    auto t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < iterations; ++i) {
        function();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto full_runtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    double avg_runtime = static_cast<double>(full_runtime) / iterations;
    std::cout << "Average runtime: " << avg_runtime << " nanoseconds\n";
}

int main() {
    const size_t iterations = 1000000;
    Hash<std::string> hashMap;

    std::string value = "Hello";
    // Benchmark put with different keys (to avoid updating same key)
    benchmark([&]() {
        static int key = 0;
        hashMap.put(key++, value);  // 1751ns
    }, iterations);

    // Benchmark contains (search for keys that exist)
    benchmark([&]() {
        static int key = 0;
        hashMap.contains(key++); //17.31ns
    }, iterations);

    // Benchmark remove for keys (must exist)
    benchmark([&]() {
        static int key = 0;
        hashMap.remove(key++); // 179ns
    }, iterations);

    return 0;
}
