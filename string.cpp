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

	for(auto it = s8.begin(); it != s8.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << s8.empty() << std::endl; /* 0 */
	std::cout << s8.size() << std::endl; /* 11 */
	std::cout << s8.length() << std::endl; /* 11 */
	std::cout << s8.max_size() << std::endl; /* 18446744073709551599 */
	std::cout << s8.capacity() << std::endl; /* 22 */
	s8.shrink_to_fit();
	std::cout << s8.capacity() << std::endl; /* 22 */

	std::string sub("wor");
	/*
	 * Finds the first substring equal to str, Search begins at pos(to right), default pos = 0
	 * */
	std::cout << static_cast<int>(s8.find(sub)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s8.find(sub, 6)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s8.find(sub, 7)) << std::endl; /* -1 */

	char sub_ch[] = "worl";
	std::cout << static_cast<int>(s8.find(sub_ch)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s8.find(sub_ch, 6)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s8.find(sub_ch, 7)) << std::endl; /* -1 */

	/*
	 *  Finds the first substring equal to the first count characters of the character string pointed to by s
	 * */
	std::cout << static_cast<int>(s8.find(sub_ch, 6, 3)) << std::endl; /* 6 */ /* pos=6, count=3 */
	std::cout << static_cast<int>(s8.find(sub_ch, 7, 3)) << std::endl; /* -1 */ /* pos=7, count=3 */

	/*
	 * Finds the first character ch, search begins at pos, default pos = 0
	 * */
	std::cout << static_cast<int>(s8.find('l')) << std::endl; /* 2 */
	std::cout << static_cast<int>(s8.find('l', 2)) << std::endl; /* 2 */

	std::string s9("hello world world");
	/*
	 * Finds the last substring equal to str, Search begins at pos(to left), default pos = npos
	 * */
	std::cout << static_cast<int>(s9.rfind(sub)) << std::endl; /* 12 */
	std::cout << static_cast<int>(s9.rfind(sub, 10)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s9.rfind(sub, 7)) << std::endl; /* 6 */

	std::cout << static_cast<int>(s9.rfind(sub_ch)) << std::endl; /* 12 */
	std::cout << static_cast<int>(s9.rfind(sub_ch, 10)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s9.rfind(sub_ch, 7)) << std::endl; /* 6 */

	std::cout << static_cast<int>(s9.rfind(sub_ch, 10, 3)) << std::endl; /* 6 */
	std::cout << static_cast<int>(s9.rfind(sub_ch, 7, 3)) << std::endl; /* 6 */

	std::cout << static_cast<int>(s9.rfind('l')) << std::endl; /* 15 */
	std::cout << static_cast<int>(s9.rfind('l', 2)) << std::endl; /* 2 */

	/* 
	 * Finds the first character equal to one of the characters in the given character sequence
	 * */
	std::cout << static_cast<int>(s9.find_first_of(sub)) << std::endl; /* 4 */
	std::cout << static_cast<int>(s9.find_first_of(sub, 10)) << std::endl; /* 12 */
	std::cout << static_cast<int>(s9.find_first_of("dlw")) << std::endl; /* 2 */
	std::cout << static_cast<int>(s9.find_first_of("dlw", 10)) << std::endl; /* 10 */
	std::cout << static_cast<int>(s9.find_first_of("dlw", 10, 2)) << std::endl; /* 10 */
	std::cout << static_cast<int>(s9.find_first_of('w', 10)) << std::endl; /* 12 */

	/* 
	 * Finds the first character equal to none of the characters in the given character sequence
	 * */
	std::cout << static_cast<int>(s9.find_first_not_of(sub)) << std::endl; /* 0 */
	std::cout << static_cast<int>(s9.find_first_not_of(sub, 10)) << std::endl; /* 10 */
	std::cout << static_cast<int>(s9.find_first_not_of("dlw")) << std::endl; /* 0 */
	std::cout << static_cast<int>(s9.find_first_not_of("dlw", 10)) << std::endl; /* 11 */
	std::cout << static_cast<int>(s9.find_first_not_of("dlw", 10, 2)) << std::endl; /* 11 */
	std::cout << static_cast<int>(s9.find_first_not_of('w', 10)) << std::endl; /* 10 */

	/* Returns a substring [pos, pos+count), return string */
	std::cout << s9.substr(6) << std::endl; /* world world */
	std::cout << s9.substr(6, -1) << std::endl; /* world world */
	std::cout << s9.substr(6, 5) << std::endl; /* world */

	char copy_str[20];
	/* Copies a substring [pos, pos+count) to char * pointed to by dest */
	s9.copy(copy_str, 5); /* count = 5, pos = 0 */
	std::cout << copy_str << std::endl; /* hello */
	s9.copy(copy_str, 5, 6); /* count = 5, pos = 6 */
	std::cout << copy_str << std::endl; /* world */

	/*
	 * Resizes the string to contain count characters.
	 * If the current size is less than count, additional characters are appended.
	 * If the current size is greater than count, the string is reduced to its first count elements.
	 * */
	std::cout << s9 << std::endl; /* hello world world */
	s9.resize(11);
	std::cout << s9 << std::endl; /* hello world */
	s9.resize(15, '!');
	std::cout << s9 << std::endl; /* hello world!!!! */

	std::string s10("233");
	s9.swap(s10);
	std::cout << s9 << std::endl; /* 233 */
	std::cout << s10 << std::endl; /* hello world!!!! */

	/*
	 * Replaces the part of the string indicated by either [pos, pos + count) or [first, last) with a new string.
	 * */
	s10.replace(0, 5, "world");
	std::cout << s10 << std::endl; /* world world!!!! */

	s10.replace(s10.begin(), s10.begin() + 5, "hello");
	std::cout << s10 << std::endl; /* hello world!!!! */

	s10.replace(s10.begin(), s10.begin() + 11, "hello");
	std::cout << s10 << std::endl; /* hello!!!! */

	s10.replace(s10.begin(), s10.begin() + 5, sub.begin(), sub.end());
	std::cout << s10 << std::endl; /* wor!!!! */

	s10.replace(3, 4, sub_ch);
	std::cout << s10 << std::endl; /* worworl */

	s10.replace(3, 4, sub_ch, 3);
	std::cout << s10 << std::endl; /* worwor */

	s10.replace(s10.begin(), s10.begin() + 3, sub_ch);
	std::cout << s10 << std::endl; /* worlwor */

	s10.replace(s10.begin(), s10.begin() + 4, sub_ch, 3);
	std::cout << s10 << std::endl; /* worwor */

	s10.replace(3, 3, 3, '!');
	std::cout << s10 << std::endl; /* wor!!! */

	s10.replace(s10.begin() + 3, s10.end(), 3, 'd');
	std::cout << s10 << std::endl; /* worddd */

	std::string base("word");
	char base_ch[] = "word";
	std::cout << s10.compare(base) << std::endl; /* 1 */
	std::cout << s10.compare(base_ch) << std::endl; /* 1 */
	std::cout << base.compare(s10) << std::endl; /* -1 */
	std::cout << s10.compare(0, 4, base) << std::endl; /* 0 */
	std::cout << s10.compare(0, 4, base_ch) << std::endl; /* 0 */
	std::cout << s10.compare(0, 4, base_ch, 3) << std::endl; /* 1 */

	s10.pop_back();
	std::cout << s10 << std::endl; /* wordd */
	s10.push_back('!');
	std::cout << s10 << std::endl; /* wordd! */

    return 0;
}
