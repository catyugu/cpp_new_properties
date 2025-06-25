#include <vector>
#include <iostream>

// Pass the vector by reference!
decltype(auto) get_nth_element(std::vector<int>& v, size_t n)
{
    // Now v[n] is a reference to an element in the ORIGINAL vector
    return v[n];
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};

    // 1. Get a value (a copy is made here for 'val')
    int val = get_nth_element(v, 1);
    std::cout << "Value at index 1 is: " << val << '\n';

    // 2. Get a reference and modify the original vector
    std::cout << "Original value at index 2: " << v[2] << '\n';
    get_nth_element(v, 2) = 99; 
    std::cout << "Modified value at index 2: " << v[2] << '\n';

    std::cout << "\nFinal vector state: ";
    for (const auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}