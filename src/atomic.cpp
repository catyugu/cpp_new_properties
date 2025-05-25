#include <iostream>
#include <thread>
#include <vector>
#include <atomic> // Required for std::atomic

// 1. Use std::atomic for the shared data. No mutex needed!
std::atomic<long long> counter = 0;

void atomic_increment() {
    for (int i = 0; i < 1000000; ++i) {
        // 3. This operation is now thread-safe and lock-free!
        counter++;
    }
}

int main() {
    // The rest of the main function is identical...
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(atomic_increment);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final atomic counter value: " << counter << std::endl;
    return 0;
}