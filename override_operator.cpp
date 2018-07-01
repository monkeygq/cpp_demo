#include <cstdio>
#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream& out, std::vector<T> &v) {
    out << "[";
    for(auto it = v.cbegin(); it != v.cend(); ++it) {
        if(it != v.cbegin())
            out << ", ";
        out << *it;
    }
    out << "]";
    return out;
}

int main() {
    std::vector<int> vi {0,1,2};
    std::cout << vi << std::endl;
    return 0;
}

/*
 * 1. override ostream operator <<
 * 2. practice using template
 * compile: g++ -std=c++11 override_operator.cpp -o override_operator
 * output: [0, 1, 2]
 */
