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
    std::vector<int> vi1;
    std::cout << "vi1 " << vi1 << std::endl;/* vi1 vector: [] */

    std::vector<int> vi2(3, 233);
    std::cout << "vi2 " << vi2 << std::endl;/* vi2 vector: [233, 233, 233] */

    std::vector<int> vi3(3);
    std::cout << "vi3 " << vi3 << std::endl;/* vi3 vector: [0, 0, 0] */

    std::vector<int> base {1, 2, 3, 4};

    std::vector<int> vi4(base.begin(), base.end());
    std::cout << "vi4 " << vi4 << std::endl;/* vi4 vector: [1, 2, 3, 4] */

    std::vector<int> vi5(vi4);
    std::cout << "vi5 " << vi5 << std::endl;/* vi5 vector: [1, 2, 3, 4] */

    std::vector<int> &ref = base;
    std::vector<int> vi6(ref);
    std::cout << "vi6 " << vi6 << std::endl;/* vi6 vector: [1, 2, 3, 4] */
    /* constructor end */

    std::vector<int> vi7;
    vi7 = base;/* copy assignment */
    std::cout << "base " << base << std::endl;/* base vector: [1, 2, 3, 4] */
    std::cout << "vi7 " << vi7 << std::endl;/* vi7 vector: [1, 2, 3, 4] */

    std::vector<int> vi8;
    vi8 = std::move(vi7);/* move assignment */
    std::cout << "vi7 " << vi7 << std::endl;/* vi7 vector: [] */
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4] */

    vi8.assign(5, 233);/* replace the contents of vector */
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [233, 233, 233, 233, 233] */
    vi8.assign(base.begin(), base.end());
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4] */

    /* returns a reference to the element at specified location pos, with bounds checking
     * if pos is not within the range of the container, an exception of type std::out_of_range is thrown
     * */
    std::cout << "vi8.at(2) = " << vi8.at(2) << std::endl;/* vi8.at(2) = 3 */

    /* returns a reference to the element at specified location pos. No bounds checking is performed */
    std::cout << "vi8[2] = " << vi8[2] << std::endl;/* vi8[2] = 3 */

	std::cout << "vi8.front() = " << vi8.front() << std::endl;/* vi8.front() = 1 */
	std::cout << "vi8.back() = " << vi8.back() << std::endl;/* vi8.back() = 4 */

	/* return a pointer to the underlying element storage. 
	 * for non-empty containers, the returned pointer compares equal to the address of the first element. 
	 * If size() is 0, data() may or may not return a null pointer.
	 * */
	int *ptr = vi8.data();
	std::cout << "*(ptr + 2) = " << *(ptr + 2) << std::endl;/* *(ptr + 2) = 3 */

	for(auto it = vi8.begin(); it != vi8.end(); ++it) {
		std::cout << *it << std::endl;
	}

	for(auto it = vi8.cbegin(); it != vi8.cend(); ++it) {
		std::cout << *it << std::endl;
	}

	for(auto it = vi8.rbegin(); it != vi8.rend(); ++it) {
		std::cout << *it << std::endl;
	}

	for(auto it = vi8.crbegin(); it != vi8.crend(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "vi8.empty() = " << vi8.empty() << std::endl;/* vi8.empty() = 0 */

	std::cout << "vi8.size() = " << vi8.size() << std::endl;/* vi8.size() = 4 */

	/*
	 * Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e.
	 * std::distance(begin(), end()) for the largest container.
	 * */
	std::cout << "vi8.max_size() = " << vi8.max_size() << std::endl;/* vi8.max_size() = 4611686018427387903 */
	std::cout << "std::distance(vi8.begin(), vi8.end()) = " << std::distance(vi8.begin(), vi8.end()) << std::endl;/* std::distance(vi8.begin(), vi8.end()) = 4 */

	std::cout << vi8.capacity() << std::endl; /* 5 */
	vi8.reserve(8);
	std::cout << vi8.capacity() << std::endl; /* 8 */
	vi8.shrink_to_fit();
	std::cout << vi8.capacity() << std::endl; /* 4 */

	/*
	 * Removes all elements from the container.
	 * Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated
	 * Leaves the capacity() of the vector unchanged
	 */
	vi8.clear();
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [] */
	std::cout << vi8.capacity() << std::endl; /* 4 */

	vi8.insert(vi8.begin(), 1);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1] */
	vi8.insert(vi8.end(), 2, 2);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 2] */
	vi8.insert(vi8.begin() + 3, 3);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 2, 3] */
	int arr[] =  {4, 5};
	/* inserts elements from range [first, last) before pos. */
	vi8.insert(vi8.end(), arr, arr + 2);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 2, 3, 4, 5] */
	std::vector<int> vi9 {6, 7};
	vi8.insert(vi8.end(), vi9.begin(), vi9.end());
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 2, 3, 4, 5, 6, 7] */

	/* return iterator following the last removed element */
	vi8.erase(vi8.begin() + 1);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4, 5, 6, 7] */
	vi8.erase(vi8.begin() + 5, vi8.end());
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4, 5] */

	/* no return */
	vi8.push_back(6);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4, 5, 6] */

	/* no return */
	vi8.pop_back();
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4, 5] */

	vi8.resize(8);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4, 5, 0, 0, 0] */
	vi8.resize(4);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4] */
	vi8.resize(8, 5);
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [1, 2, 3, 4, 5, 5, 5, 5] */


    std::cout << "vi7 " << vi7 << std::endl;/* vi7 vector: [] */
	vi8.swap(vi7);
    std::cout << "vi7 " << vi7 << std::endl;/* vi7 vector: [1, 2, 3, 4, 5, 5, 5, 5] */
    std::cout << "vi8 " << vi8 << std::endl;/* vi8 vector: [] */
}
















