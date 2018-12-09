#include <iostream>
#include <memory>
#include <string>

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec& sv);
    StrVec& operator=(const StrVec& sv);
    ~StrVec() {
        free();
    }
    void push_back(const std::string& str);
    std::size_t size() const {
        return first_free - elements;
    };
    std::size_t capacity() const {
        return cap - elements;
    }
    std::string* begin() const {
        return elements;
    }
    std::string* end() const {
        return first_free;
    }
private:
    std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string* b, const std::string* e);
    void free();
    void reallocate();
    std::string* elements;
    std::string* first_free;
    std::string* cap;
};

void StrVec::push_back(const std::string& str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &sv){
    auto res = alloc_n_copy(sv.begin(), sv.end());
    elements = res.first;
    first_free = cap = res.second;
}

StrVec& StrVec::operator=(const StrVec &sv) {
    free();
    auto res = alloc_n_copy(sv.begin(), sv.end());
    elements = res.first;
    first_free = cap = res.second;
    return *this;
}

void StrVec::reallocate() {
    std::size_t len = size();
    auto new_cap = capacity() ? capacity() * 2 : 1;
    auto res = alloc.allocate(new_cap);
    auto elem_tmp = res;
    for(auto p = elements; p < first_free; p++) {
        alloc.construct(res++, std::move(*p));
    }
    free();
    elements = elem_tmp;
    first_free = elem_tmp + len;
    cap = elem_tmp + new_cap;
}

void my_print(StrVec& sv) {
    for (auto it = sv.begin(); it != sv.end(); ++it )
        std::cout << *it << std::endl;
}
int main() {
    StrVec sv;
    sv.push_back("hougq");
    sv.push_back("buaa");
    sv.push_back("lcx");
    sv.push_back("pku");
    StrVec sv1(sv);
    StrVec sv2;
    sv2 = sv1;
    my_print(sv1);
    my_print(sv2);
    return 0;
}

/*
 * OUTPUT:
 * hougq
 * buaa
 * lcx
 * pku
 * hougq
 * buaa
 * lcx
 * pku
 */
