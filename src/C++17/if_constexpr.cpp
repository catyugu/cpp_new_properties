#include <type_traits>
#include <iostream>
#include <string>

template <typename T>
decltype(auto) to_string_custom(T value){
    if constexpr(std::is_arithmetic_v<T>){
        return std::to_string(value);
    }else {
        return value;
    }
}
int main(){
    std::cout << to_string_custom(42) << std::endl;
    std::cout << to_string_custom("Hello") << std::endl;
}