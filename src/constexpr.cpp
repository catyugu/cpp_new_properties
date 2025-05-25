#include <iostream>
#include <array>
#include <cstddef> // For std::size_t

constexpr long long Factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main() {
    // 2. Use the constexpr function to declare an array size.
    //    The compiler will calculate Factorial(5) and create an array of size 120.
    constexpr int array_size_input = 5;
    std::array<int, Factorial(array_size_input)> my_array;

    std::cout << "The size of my_array is: " << my_array.size() << std::endl;

    // 3. Use the constexpr function in a static_assert for compile-time validation.
    static_assert(Factorial(20) == 2432902008176640000, "The factorial calculation for 4 is incorrect!");

    // Bonus "failure" test. Uncomment the line below to see the compilation fail.
    // static_assert(Factorial(6) == 123, "This assertion will fail at compile time!");

    std::cout << "Program compiled and ran successfully!" << std::endl;

    return 0;
}