#include "SimpleClass.hpp"
#include <iostream>

SimpleClass::SimpleClass() {}
SimpleClass::~SimpleClass() {}

void SimpleClass::simpleMethod() {
    std::cout << "SimpleMethod\n";
}

int SimpleClass::callMe(int num) {
    return num;
}
