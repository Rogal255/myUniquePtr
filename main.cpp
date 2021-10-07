#include <iostream>
#include <utility>
#include "unique_ptr.hpp"

class SimpleClass {
public:
    SimpleClass() {
        std::cout << "SimpleClass c'tor\n";
    }
    ~SimpleClass() {
        std::cout << "SimpleClass d'tor\n";
    }

    void simpleMethod() {
        std::cout << "SimpleMethod\n";
    }
};

int main() {
    pr::unique_ptr up{new SimpleClass};
    up->simpleMethod();
    (*up).simpleMethod();
    // pr::unique_ptr new_instance = up;
    // pr::unique_ptr new_instance{up};
    pr::unique_ptr<SimpleClass> new_instance{nullptr};
    new_instance = std::move(up);
    pr::unique_ptr even_newer_instance{std::move(new_instance)};
    return 0;
}
