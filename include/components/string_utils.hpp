#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

namespace components {

inline std::string_view trim_left(std::string_view text) {
    while (!text.empty() &&
           (text.front() == ' ' || text.front() == '\t' ||
            text.front() == '\n' || text.front() == '\r')) {
        text.remove_prefix(1);
    }
    return text;
}

inline std::string_view trim_right(std::string_view text) {
    while (!text.empty() &&
           (text.back() == ' ' || text.back() == '\t' ||
            text.back() == '\n' || text.back() == '\r')) {
        text.remove_suffix(1);
    }
    return text;
}

inline std::string_view trim(std::string_view text) {
    return trim_left(trim_right(text));
}

inline std::vector<std::string_view> split(std::string_view text,
                                           std::string_view delimiter) {
    std::vector<std::string_view> parts;
    if (delimiter.empty()) {
        parts.push_back(text);
        return parts;
    }

    std::size_t start = 0;
    while (true) {
        const std::size_t position = text.find(delimiter, start);
        if (position == std::string_view::npos) {
            parts.emplace_back(text.substr(start));
            break;
        }
        parts.emplace_back(text.substr(start, position - start));
        start = position + delimiter.size();
    }
    return parts;
}

inline std::string join(const std::vector<std::string_view>& parts,
                        std::string_view separator) {
    std::string result;
    for (std::size_t index = 0; index < parts.size(); ++index) {
        if (index != 0) {
            result.append(separator);
        }
        result.append(parts[index]);
    }
    return result;
}

}  // namespace components
