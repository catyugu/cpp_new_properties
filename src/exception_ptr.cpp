#include <iostream>
#include <thread>
#include <exception>   // Required for std::exception_ptr, etc.
#include <stdexcept>   // Required for std::runtime_error
#include <functional>  // Required for std::ref

// 1. The worker function that will fail.
void worker_thread_function(std::exception_ptr& error_ptr) {
    try {
        // 2. Simulate a failure.
        std::cout << "Worker thread: Starting a failing operation...\n";
        throw std::runtime_error("Something went wrong in the worker thread!");

    } catch (...) {
        // 3. Capture the current exception into the shared pointer.
        std::cout << "Worker thread: Caught exception, storing it...\n";
        error_ptr = std::current_exception();
    }
}

int main() {
    // 4. Create the shared pointer to hold a potential exception.
    std::exception_ptr worker_exception_ptr = nullptr;

    std::cout << "Main thread: Launching worker thread...\n";
    // 5. Launch the thread, passing a reference to our pointer.
    std::thread worker(worker_thread_function, std::ref(worker_exception_ptr));

    // 6. Wait for the thread to finish its job.
    worker.join();
    std::cout << "Main thread: Worker thread has finished.\n";

    // 7. & 8. Check if the worker thread reported an error.
    try {
        if (worker_exception_ptr) {
            std::cout << "Main thread: Exception pointer is set. Rethrowing exception...\n";
            std::rethrow_exception(worker_exception_ptr);
        } else {
            std::cout << "Main thread: Worker finished without errors.\n";
        }
    } catch (const std::exception& e) {
        // This block now successfully handles the exception from the other thread!
        std::cout << "Main thread: Caught exception! Message: '" << e.what() << "'\n";
    }

    return 0;
}