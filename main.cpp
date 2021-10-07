#include <utility>
#include "SimpleClass.hpp"
#include "unique_ptr.hpp"

int main() {
    pr::unique_ptr ptr1{new SimpleClass};
    ptr1->simpleMethod();
    (*ptr1).simpleMethod();
    // pr::unique_ptr ptr2{ptr1};
    // pr::unique_ptr<SimpleClass> ptr3{nullptr};
    // pr::unique_ptr ptr3 = ptr2;
    pr::unique_ptr ptr2{std::move(ptr1)};
    pr::unique_ptr<SimpleClass> ptr3{nullptr};
    ptr3 = std::move(ptr2);
    return 0;
}
