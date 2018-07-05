#include <cstdio>
#include <iostream>
#include <vector>


std::ostream &operator<<(std::ostream &out, std::vector<int> &v) {
    out << "vector: [";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if(it != v.begin())
            out << ", ";
        out << *it;
    }
    out << "]";
    return out;
}

int main() {
    /* constructor */
    std::vector<int> vs1;
    std::cout << "vs1 " << vs1 << std::endl;/* vs1 vector: [] */

    std::vector<int> vs2(3, 233);
    std::cout << "vs2 " << vs2 << std::endl;/* vs2 vector: [233, 233, 233] */

    std::vector<int> vs3(3);
    std::cout << "vs3 " << vs3 << std::endl;/* vs3 vector: [0, 0, 0] */

    std::vector<int> base {1, 2, 3, 4};

    std::vector<int> vs4(base.begin(), base.end());
    std::cout << "vs4 " << vs4 << std::endl;/* vs4 vector: [1, 2, 3, 4] */

    std::vector<int> vs5(vs4);
    std::cout << "vs5 " << vs5 << std::endl;/* vs5 vector: [1, 2, 3, 4] */

    std::vector<int> &ref = base;
    std::vector<int> vs6(ref);
    std::cout << "vs6 " << vs6 << std::endl;/* vs6 vector: [1, 2, 3, 4] */
    /* constructor end */

    std::vector<int> vs7;
    vs7 = base;/* copy assignment */
    std::cout << "base " << base << std::endl;/* base vector: [1, 2, 3, 4] */
    std::cout << "vs7 " << vs7 << std::endl;/* vs7 vector: [1, 2, 3, 4] */

    std::vector<int> vs8;
    vs8 = std::move(vs7);/* move assignment */
    std::cout << "vs7 " << vs7 << std::endl;/* vs7 vector: [] */
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1, 2, 3, 4] */

    vs8.assign(5, 233);/* replace the contents of vector */
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [233, 233, 233, 233, 233] */
    vs8.assign(base.begin(), base.end());
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1, 2, 3, 4] */

    /* returns a reference to the element at specified location pos, with bounds checking
     * if pos is not within the range of the container, an exception of type std::out_of_range is thrown
     * */
    std::cout << "vs8.at(2) = " << vs8.at(2) << std::endl;/* vs8.at(2) = 3 */

    /* returns a reference to the element at specified location pos. No bounds checking is performed */
    std::cout << "vs8[2] = " << vs8[2] << std::endl;/* vs8[2] = 3 */

	std::cout << "vs8.front() = " << vs8.front() << std::endl;/* vs8.front() = 1 */
	std::cout << "vs8.back() = " << vs8.back() << std::endl;/* vs8.back() = 4 */

	/* return a pointer to the underlying element storage. 
	 * for non-empty containers, the returned pointer compares equal to the address of the first element. 
	 * If size() is 0, data() may or may not return a null pointer.
	 * */
	int *ptr = vs8.data();
	std::cout << "*(ptr + 2) = " << *(ptr + 2) << std::endl;/* *(ptr + 2) = 3 */

	for(auto it = vs8.begin(); it != vs8.end(); ++it) {
		std::cout << *it << std::endl;
	}

	for(auto it = vs8.cbegin(); it != vs8.cend(); ++it) {
		std::cout << *it << std::endl;
	}

	for(auto it = vs8.rbegin(); it != vs8.rend(); ++it) {
		std::cout << *it << std::endl;
	}

	for(auto it = vs8.crbegin(); it != vs8.crend(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "vs8.empty() = " << vs8.empty() << std::endl;/* vs8.empty() = 0 */

	std::cout << "vs8.size() = " << vs8.size() << std::endl;/* vs8.size() = 4 */

	/*
	 * Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e.
	 * std::distance(begin(), end()) for the largest container.
	 * */
	std::cout << "vs8.max_size() = " << vs8.max_size() << std::endl;/* vs8.max_size() = 4611686018427387903 */
	std::cout << "std::distance(vs8.begin(), vs8.end()) = " << std::distance(vs8.begin(), vs8.end()) << std::endl;/* std::distance(vs8.begin(), vs8.end()) = 4 */

	std::cout << vs8.capacity() << std::endl; /* 5 */
	vs8.reserve(8);
	std::cout << vs8.capacity() << std::endl; /* 8 */
	vs8.shrink_to_fit();
	std::cout << vs8.capacity() << std::endl; /* 4 */

	/*
	 * Removes all elements from the container.
	 * Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated
	 * Leaves the capacity() of the vector unchanged
	 */
	vs8.clear();
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [] */
	std::cout << vs8.capacity() << std::endl; /* 4 */

	vs8.insert(vs8.begin(), 1);
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1] */
	vs8.insert(vs8.end(), 2, 2);
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1, 2, 2] */
	vs8.insert(vs8.begin() + 3, 3);
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1, 2, 2, 3] */
	int arr[] =  {4, 5};
	/* inserts elements from range [first, last) before pos. */
	vs8.insert(vs8.end(), arr, arr + 2);
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1, 2, 2, 3, 4, 5] */
	std::vector<int> vs9 {6, 7};
	vs8.insert(vs8.end(), vs9.begin(), vs9.end());
    std::cout << "vs8 " << vs8 << std::endl;/* vs8 vector: [1, 2, 2, 3, 4, 5, 6, 7] */
}
















