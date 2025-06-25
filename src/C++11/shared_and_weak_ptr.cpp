#include <iostream>
#include <memory> 
#include <string>
struct Person{
    std::string name;
    std::weak_ptr<Person> closest_companion;
    ~Person(){
        std::cout << name << " is destroyed" << std::endl;
    }
};

int main(){
    auto p1 = std::make_shared<Person>();
    p1->name = "Alice";
    auto p2 = std::make_shared<Person>();
    p2->name = "Bob";
    p1->closest_companion = p2;
    p2->closest_companion = p1;
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;
    std::cout << "p2.use_count() = " << p2.use_count() << std::endl;
    return 0;

}