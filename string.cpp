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
	print_char_ptr(&str[0]); /* h */
	std::cout << str << std::endl; /* hel3o */

	std::string s1;
	std::string s2(5, 'b');
	std::cout << s2 << std::endl; /* bbbbb */

	/* constructs the string with a substring [pos, pos+count) of other string*/
	std::string s3(s2, 1, 3); /* other string:s2, pos:1, count:3 */
	std::cout << s3 << std::endl; /* bbb */

	char ch[] = "hello world";
	/* Constructs the string with the first count characters of char*    */
	std::string s4(ch, 8); /* count:8 */
	std::cout << s4 << std::endl; /* hello wo */

	/* constructs the string with char*    */
	std::string s5(ch);
	std::cout << s5 << std::endl; /* hello world */

	std::string s6(s5.begin(), s5.begin() + 3);
	std::cout << s6 << std::endl; /* hel */

	std::string s7(s5);
	std::cout << s7 << std::endl; /* hello world */

	/* move constructor, right hand side reference */
	std::string s8(std::string("hello") + std::string("world"));
	std::cout << s8 << std::endl; /* helloworld */

	s8.assign(5, 'b');
	s8.assign(s7);
	s8.assign(s7, 1, 3);
	s8.assign(std::string("hello") + std::string("world"));
	s8.assign(ch, 8);
	s8.assign(ch);
	s8.assign(s5.begin(), s5.end());
	std::cout << s8 << std::endl; /* hello world */

	std::cout << s8.at(3) << std::endl; /* l */
	std::cout << s8[3] << std::endl; /* l */
	std::cout << s8.front() << std::endl; /* h */
	std::cout << s8.back() << std::endl; /* d */
	std::cout << s8.data() << std::endl; /* hello world */

	std::cout << (void*)(s8.data()) << std::endl; /* 0x7ffeea3ca719 */
	/* str.data() return a pointer that points to const char*  */
	std::cout << static_cast<const void*>(s8.data()) << std::endl; /* 0x7ffeea3ca719 */
	/* str.c_str() return a pointer that points to const char*, the pointer is same to str.data()  */
	std::cout << static_cast<const void*>(s8.c_str()) << std::endl; /* 0x7ffeea3ca719 */
    return 0;
}
