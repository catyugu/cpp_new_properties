#include <vector>
#include <iostream>
int main(){
    std::vector<int> vec{1,2,3,4,5};
    for (const auto& elem : vec){
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
    for (auto& elem : vec){
        elem += 100;
    }
    for (const auto& elem : vec){
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}