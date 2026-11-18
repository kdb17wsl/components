#include <cstdlib>
#include <iostream>
#include <concepts>

namespace {
void check(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(EXIT_FAILURE);
    }
}
}  // namespace

template <typename T>
concept Incrementable = requires(T value) {
    ++value;
};

template <Incrementable T>
void increment(T& value) {
    ++value;
}

int main() {
    int value = 0;
    increment(value);
    check(value == 1, "C++20 concepts and increment");

    return 0;
}
