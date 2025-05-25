#include <iostream>
#include <memory> 

// The Resource class
struct Resource {
    Resource() { std::cout << "Resource created\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }

    void doSomething() { std::cout << "Resource in use\n"; }
};

void useResource(std::unique_ptr<Resource> res) {
    if (res) {
        res->doSomething();
    }
} 
int main() {
    // Create a unique_ptr to a Resource object.
    auto resourcePtr = std::make_unique<Resource>();
    // Call useResource and transfer ownership of your pointer.
    useResource(std::move(resourcePtr));
    auto movedPtr = std::move(resourcePtr);

    std::cout << "main function is ending\n";
    return 0;
}