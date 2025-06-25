#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Person{
    std::string name;
    int age;
};

int main(){
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"David", 28}
    };
    int min_age = 27;
    std::for_each(people.begin(), people.end(), [min_age](const Person& person){
        if(person.age >= min_age){
            std::cout << person.name << " is " << person.age << " years old." << std::endl;
        }
    });
}