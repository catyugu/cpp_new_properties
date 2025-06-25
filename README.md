# Modern C++ Features: A Guided Summary (C++11, 14, 17)

This document summarizes key features introduced in C++11, C++14, and C++17, providing a quick reference for modern C++ programming practices.

## C++11

C++11 was a monumental release that fundamentally changed how C++ is written, making it safer, more efficient, and more expressive.

* **`auto` Keyword**:
    * Enables automatic type deduction for variables at compile-time, reducing verbosity and improving code maintainability.

* **Range-Based `for` Loops**:
    * Provides a clean and simple syntax (`for (auto& item : container)`) for iterating over all elements in a range or container, eliminating manual iterator management.

* **Lambda Expressions**:
    * Allows for the creation of inline, anonymous function objects, perfect for custom logic in standard algorithms (`std::sort`, `std::find_if`, etc.).

* **Smart Pointers (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`)**:
    * Automates memory and resource management using the RAII principle, preventing memory leaks and making codeexception-safe.
    * `std::unique_ptr`: Exclusive ownership.
    * `std::shared_ptr`: Shared ownership with reference counting.
    * `std::weak_ptr`: Non-owning observer to break `shared_ptr` ownership cycles.

* **Move Semantics & R-value References (`&&`)**:
    * Introduces the ability to "move" resources from temporary objects instead of copying them, dramatically improving performance for resource-heavy objects like containers. `std::move` is used to signal that an object can be moved from.

* **Uniform Initialization (`{}`) & `std::initializer_list`**:
    * Provides a consistent initialization syntax for all types and prevents unsafe "narrowing" conversions. Enables custom classes to be initialized with a list of values.

## C++14

C++14 was a refinement of C++11, focused on quality-of-life improvements and making existing features more powerful and convenient.

* **Generic Lambdas**:
    * Allows the use of `auto` in a lambda's parameter list, turning the lambda into a flexible function template that can operate on different types.

* **Function Return Type Deduction**:
    * Allows `auto` to be used as the return type for normal functions, simplifying function template signatures by having the compiler deduce the return type from `return` statements.

## C++17

C++17 continued the trend of adding powerful new features and conveniences to the language and standard library.

* **Structured Bindings**:
    * Allows for the direct unpacking of `struct`, `std::pair`, or `std::tuple` members into distinct variables, making code more readable (e.g., `auto [key, value] : my_map`).

* **`if constexpr`**:
    * A compile-time `if` statement that evaluates its condition at compile time and discards the branch that is not taken, allowing a single function template to have different logic for different types without compile errors.
