#include <iostream>
#include <thread>
#include <vector>
#include <mutex> // Required for mutex and lock_guard

// 1. Shared data and the mutex to protect it
long long counter = 0;
std::mutex mtx;

// 3. The function each thread will run
void increment() {
    long long local_counter = 0;
    for (int i = 0; i < 1000000; ++i) {
        local_counter++;
    }

    // Now, lock just ONCE to add the sub-total to the global total
    std::lock_guard<std::mutex> lock(mtx);
    counter += local_counter;
}

int main() {
    // 4. Create a vector to hold the threads
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(increment); // Create and run the thread
    }

    // 5. Wait for all threads to finish
    for (auto& t : threads) {
        t.join(); // The main thread blocks here until 't' has finished
    }

    // 6. Print the final result
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}