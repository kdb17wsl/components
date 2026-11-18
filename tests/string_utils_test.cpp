#include "components/string_utils.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace {
void check(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(EXIT_FAILURE);
    }
}
}  // namespace

int main() {
    using namespace components;

    check(trim(" \t hello\r\n") == "hello", "trim");
    check(trim_left("  left") == "left", "trim_left");
    check(trim_right("right  ") == "right", "trim_right");

    const std::vector<std::string_view> parts = split("a,b,c", ",");
    check(parts.size() == 3, "split size");
    check(parts[0] == "a", "split first part");
    check(parts[1] == "b", "split second part");
    check(parts[2] == "c", "split third part");

    check(join(parts, "-") == "a-b-c", "join");
    check(join(split("", ","), "-").empty(), "split empty string");
    check(join(split("word", ""), "-") == "word", "split empty delimiter");

    return 0;
}
