#ifndef LEETCODE_UTIL_H
#define LEETCODE_UTIL_H

#include <string>
#include <vector>

namespace leetcode {

// Join a vector to string.
template <class T>
inline std::string to_string(std::vector<T> v, std::string joiner=",") {
    if (v.empty()) return "[]";
    std::string s;
    for (auto iter = v.begin(); iter < v.end() - 1; ++iter)
        s += to_string(*iter) + joiner;
    return "[" + s + to_string(v.back()) + "]";
}

}

#endif
