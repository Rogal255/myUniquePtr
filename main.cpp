#include <iostream>
#include "unique_ptr.hpp"

class SimpleClass {
public:
    SimpleClass() {
        std::cout << "c'tor\n";
    }
    ~SimpleClass() {
        std::cout << "d'tor\n";
    }

    void simpleMethod() {
        std::cout << "Simple Method\n";
    }
};

int main() {
    pr::unique_ptr up(new SimpleClass);
    up->simpleMethod();
    (*up).simpleMethod();
    return 0;
}
