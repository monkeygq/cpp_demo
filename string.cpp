#include <iostream>
#include <string>
#include <vector>

void print_string(const char *s) {
    std::cout << s << std::endl;
}

void print_char(char s) {
    std::cout << s << std::endl;
}

void print_char_ptr(char *s) {
	*(s + 3) = '3';
    std::cout << *s << std::endl;
}

int main() {
    std::string str("hello");

	/*
	 * The elements of a string are stored contiguously
	 * for a string s, &*(s.begin() + n) == &*s.begin() + n for any n in [0, s.size())
	 */
    for(int i = 0; i < str.size(); i++) {
        std::cout << &*(str.begin() + i) << " " << &*(str.begin()) + i << std::endl;
    }

	/* str.c_str() return const char*    */
    print_string(str.c_str()); /* hello */

	/* s[n] can be passed to functions that expect a char    */
    print_char(str[0]); /* h */

	/* a pointer to s[n] can be passed to functions that expect a char*    */
	print_char_ptr(&str[0]); /* e */
	std::cout << str << std::endl;
    return 0;
}
