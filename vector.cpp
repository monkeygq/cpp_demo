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
}
















