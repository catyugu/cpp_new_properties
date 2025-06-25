#include <vector>
#include <iostream>
#include <string>
#include <numeric> // For std::accumulate, a better way to sum

int main() {
    auto summer = [](const auto& vec) {
        using ElementType = typename std::decay_t<decltype(vec[0])>;
        
        ElementType sum{}; // Default-construct the "zero" value (0 for int, "" for string)
        
        for (const auto& i : vec) {
            sum += i;
        }
        return sum;
    };

    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<std::string> v2{"Hello", " ", "World", "!"};
    
    std::cout << summer(v1) << '\n';
    std::cout << summer(v2) << '\n';
}