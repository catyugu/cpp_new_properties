#include <iostream>
#include <memory> 

struct Resource {
    Resource() { std::cout << "Resource created\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }

    void doSomething() { std::cout << "Resource in use\n"; }
};

// 4. The function that shares ownership
void shareTheResource(std::shared_ptr<Resource> res) {
    // 5. Print the use count inside the function
    std::cout << "  (In function) Resource use count: " << res.use_count() << "\n";
    res->doSomething();
    std::cout << "  (In function) Leaving the function...\n";
} // <-- The 'res' copy is destroyed here, and the reference count decreases.

int main() {
    // 2. Create a shared_ptr to a Resource object.
    auto sharedRes = std::make_shared<Resource>();

    // 3. Print the use count before calling the function.
    std::cout << "(In main) Resource use count: " << sharedRes.use_count() << "\n";

    // 6. Call the function to share the pointer.
    //    Notice we don't need std::move(). We are making a copy.
    shareTheResource(sharedRes);

    // 7. Print the use count after the function has returned.
    std::cout << "(In main) Resource use count after function call: " << sharedRes.use_count() << "\n";

    std::cout << "(In main) main function is ending\n";
    return 0;
} // <-- The original 'sharedRes' is destroyed here, the count becomes 0, and the Resource is destroyed.