#include <iostream>
#include <memory>

struct Engine{
    Engine(){
        std::cout << "Engine started" << std::endl;
    }
    ~Engine(){
        std::cout << "Engine stopped" << std::endl;
    }
};

struct Car{
    std::unique_ptr<Engine> engine;
    Car() : engine(std::make_unique<Engine>()) {
        // Constructor body can be empty or used for other logic
    }
};
int main() {
    std::cout << "Entering main scope...\n";
    {
        std::cout << "  Entering inner scope...\n";
        Car car;
        std::cout << "  ...leaving inner scope.\n";
    } // 'car' goes out of scope here, destructor is called
    std::cout << "Left main scope.\n";
    return 0;
}